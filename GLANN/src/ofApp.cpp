#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofEnableAlphaBlending();

    mWorker = new GLANN();
    mWorker->initGLANN(256);

    mNetwork = new ANNData( 256, 0.4, 1.0, 0.05);

    frameCounter = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    vector<float> input;
    for(int i = 0; i < 256; i++)
        input.push_back((1.0+sinf(((frameCounter % 256)/10.0)*i/256.0))/2.0);
    vector<float> output = mWorker->propergateFW(input,mNetwork);

    vector<float> target;
    for(int i = 0; i < 256; i++)
        target.push_back(0.5);
    target[frameCounter%256] = 1.0;

    vector<float> error;
    for(int i = 0; i < 256; i++)
        error.push_back((target[i]-output[i])*output[i]*(1.0-output[i]));

    //mWorker->propergateBW(input,error,mNetwork);

    mWorker->draw(mNetwork);

    //Render output
    ofSetColor(255);
    for(int i = 1; i < 256; i++)
        ofLine(256+i,output[i-1]*50+50,256+i+1,output[i]*50+50);


    ofSetColor(255);
    for(int i = 1; i < 256; i++)
        ofLine(256+i,input[i-1]*50+150,256+i+1,input[i]*50+150);

    cout << frameCounter++ << "\n";
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
