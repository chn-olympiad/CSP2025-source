#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string rep(string container, string target,string replacer){
    if(container.length()<target.length())return container;
    for(int i = 0;i<=container.length()-target.length();i++){
        int flag = 1;
        for(int j = 0;j<target.length();j++){
            if(container[i+j] != target[j]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            for(int k = 0;k<target.length();k++){
                container[i+k] = replacer[k];
            }
            return container;
        }
    }
    return container;
}

string li[200000];
string li2[200000];
int main(){
    ifstream infile;
    ofstream outfile;
    infile.open("replace.in");
    outfile.open("replace.out");
    int n,p;
    infile >> n >> p;
    for(int i = 0;i<n;i++){
        infile >> li[i] >> li2[i];
        // cout << li[i] << " " << li2[i] << endl;
    }
    for(int j = 0;j<p;j++){
        string b,c;
        infile >> b >> c;
        int ou = 0;
        for(int k = 0;k<n;k++){
            // cout << rep(b,li[k],li2[k]) << endl;
            if(rep(b,li[k],li2[k])==c)ou++;
        }
        outfile << ou << endl;
    }
    // cout << rep("abcq","cq","cb");
    return 0;
}