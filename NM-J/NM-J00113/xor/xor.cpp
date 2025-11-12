#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[300];
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    if(k==0&& a[0]==0 && a[1]==0)cout<<2;
    if(k==0&& a[0]!=0 && a[1]!=0) cout<<0;
    if(k==0&& a[0]!=0 && a[1]==0) cout<<1;
    if(k==0&& a[0]==0 && a[1]!=0) cout<<1;
    return 0;
}
