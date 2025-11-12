#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","w",stdin);
    freopen("xor.out","w",stdout);
    int n,k,shu[500055],ct = 0;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {cin>>shu[i];if(shu[i]==0) ct++;}
    if(k==0) cout<<ct;

    return 0;
}
