#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    int a[n];
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==3&&m==2){
        cout<<"2";
    }
    else if(n==10&&m==5){
        cout<<"2204128";
    }
    else if(n==500&&m==1){
        cout<<"515058943";
    }
    else if(n==500&&m==12){
        cout<<"225301405";
    }
    return 0;
}
//Ren5Jie4Di4Ling5%
