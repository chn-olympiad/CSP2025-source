#include<bits/stdc++.h>
using namespace std;
int a[10],s[10],d;
int main(){
    //freopen("number.in","r","stdin")
    //freopen("number.out","w","stdout")
    string s;
    cin>>s;


        if(s.find("0")!=string::npos)d=s.find("0");
        if(s.find("1")!=string::npos)a[1]=1;
        if(s.find("2")!=string::npos)a[2]=2;
        if(s.find("3")!=string::npos)a[3]=3;
        if(s.find("4")!=string::npos)a[4]=4;
        if(s.find("5")!=string::npos)a[5]=5;
        if(s.find("6")!=string::npos)a[6]=6;
        if(s.find("7")!=string::npos)a[7]=7;
        if(s.find("8")!=string::npos)a[8]=8;
        if(s.find("9")!=string::npos)a[9]=9;

    for(int p=9;p>=0;p--){
            for(int z;z<s.find(p);z++){
        if(a[p]!=0)cout<<a[p];
            }
    }
    for(int w=0;w<d;w++){
        cout<<"0";
    }


    return 0;
}
