#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxa;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(a[i],maxa);
    }
    if(a[1]+a[2]+a[3]>maxa*2)cout<<1;
    else cout<<0;
    return 0;
}
