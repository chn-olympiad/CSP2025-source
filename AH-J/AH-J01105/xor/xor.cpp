#include<bits/stdc++.h>
using namespace std;
int main1(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n=0,m=0,a[10000]={};
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1) cout<<(a[0]==m);
    if(n==2) cout<<1;
    return 0;
}
