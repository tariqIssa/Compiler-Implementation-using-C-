#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int isKeyword(string s){
    return (s=="typedef"||s=="short"||s=="return"||s=="static"||s=="const"||s=="case"||s=="switch"||s=="long"||s=="break"||s=="void"||s=="int"||s=="float"||s=="double"||s=="cin"||s=="cout"||s=="bool"||s=="opperator"||s=="class"||s=="if"||s=="else"||s=="while"||s=="for"||s=="do");

    
    
}
int main(){
    string x;//char *tmp;
    string tmp;
    ifstream infile;
    ofstream outfile;
    infile.open("in.txt");
    outfile.open("out.txt");
    int i,j=0,line=0,flag=1;
    outfile<<"line    type     spelling    start    length"<<endl;
    outfile<<"----------------------------------------------------"<<endl;
    while (!infile.eof()){
    getline (infile,x);
    line++;
    for (i=0;i<x.length()&&flag==1;i++){
        if(x[i]=='/'&&x[i+1]=='/')flag=0;
        else if(x[i]=='('||x[i]==')'||x[i]=='{'||x[i]=='}'||x[i]=='['||x[i]==']'){
            outfile<<line<<"    paranthisis   "<<x[i]<<"          "<<i+1<<"         "<<1<<endl;
        }
        else if ((x[i]=='-'||x[i]=='*'||x[i]=='/'||x[i]=='+')&&(x[i+1]=='=')){
            outfile<<line<<"    "<<"assign    "<<x[i]<<x[i+1]<<"    "<<i+1<<"   "<<2<<endl;
            i++;
        }
        else if(x[i]=='='){
            outfile<<line<<"    "<<"assign        "<<x[i]<<"          "<<i+1<<"          "<<1<<endl;
        }
        else if((x[i]=='<'&&x[i+1]=='<')||(x[i]=='>'&&x[i+1]=='>')||(x[i]=='='&&x[i+1]=='=')||(x[i]=='>'&&x[i+1]=='=')||(x[i]==','&&x[i+1]=='=')||(x[i]=='!'&&x[i+1]=='=')){
            outfile<<line<<"    "<<"operator    "<<x[i]<<x[i+1]<<"          "<<i+1<<"           "<<2<<endl;
            i++;
        }        
        else if(x[i]=='+'||x[i]=='-'||x[i]=='*'||x[i]=='/'||x[i]=='%'){
            outfile<<line<<"    "<<"operator     "<<x[i]<<"             "<<i+1<<"          "<<1<<endl; 
        }

        else if(x[i]==','||x[i]==';'||x[i]=='?'||x[i]==':'||x[i]=='"'){
            outfile<<line<<"    "<<"punctution    "<<x[i]<<"           "<<i+1<<"            "<<1<<endl; 
        }
        else if(x[i]>='0'&&x[i]<='9'){
            
            do {
                
                tmp.push_back(x[i++]);
                j++;
            }while(x[i]&&(x[i]>='0'&&x[i]<='9'));
            
           
            outfile<<line<<"    "<<"number       "<<tmp<<"           "<<i-j+1<<"          "<<j<<endl; 
            i--;
            j=0;
            tmp.erase();
        }
        else if(x[i]>='a'&&x[i]<='z'){
            
            do {
                
                tmp.push_back(x[i++]);
                j++;
            }while(x[i]&&(x[i]>='a'&&x[i]<='z'));
            
            if(isKeyword(tmp))
                outfile<<line<<"    "<<"keyword     "<<tmp<<"           "<<i-j+1<<"          "<<j<<endl;
            else 
                outfile<<line<<"    "<<"identifier    "<<tmp<<"            "<<i-j+1<<"         "<<j<<endl;
            i--;
            j=0;
            tmp.erase();
        }        
        
        
        
        
    }



    
    flag=1;
        
    }
cout<<" ---The lexical Done  ---\n";    
    return 0;
}