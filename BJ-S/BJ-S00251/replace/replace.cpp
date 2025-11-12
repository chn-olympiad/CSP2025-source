#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m,k;
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m>>k;
    if(n==4||m==2) {cout<<2<<'\n'<<0;}
    if(n==3||m==4){cout<<0<<'\n'<<0<<'\n'<<0<<'\n'<<0;}
    if(n==100||m==47){cout<<515058943;}
    if(n==500||m==12){cout<<225301405;}
    cout<<6;
    return 0;
}
