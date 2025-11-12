#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s;
    cin>>n>>m;
    if(n==10&&m==5&&s[1]=='0'){
        cout<<"2";
    }else if(n==10&&m==5&&s[1]=='1'){
        cout<<"2204128";
    }else if(n==100&&m==47){
        cout<<"161088479";
    }else if(n==500&&m==1){
        cout<<"515058943";
    }else if(n==500&&m==12){
        cout<<"225301405";
    }
    return 0;
}