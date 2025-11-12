#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,f=0,cnt=0,v[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
        if(v[i]==1) {ans++; cnt++;}
        if(v[i]==0) {f++; f+=cnt/2; cnt=0;}
    }
    f+=cnt/2;
    if(k)cout<<ans;
    else cout<<f;
}