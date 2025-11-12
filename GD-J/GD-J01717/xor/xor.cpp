#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,INF=0x3f3f3f3f;
int n,k,a[N],c[1919810],f[N],as;
int main(){
#ifndef ASTRALFLARE_CE
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
#endif
    cin>>n>>k;
    fill(c,c+1919810,-INF);
    for(int i=1;i<=n;++i){cin>>a[i];a[i]^=a[i-1];}
    c[0]=0;
    for(int i=1;i<=n;++i){
        f[i]=max(f[i-1],max(0,c[a[i]^k]+1));
        as=max(as,c[a[i]]=max(c[a[i]],f[i]));
    }
    cout<<as;
}