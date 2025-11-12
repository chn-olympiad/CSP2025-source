#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3,mod=998244353;
int n,a[N+10],ans,cnt,b[N+10];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==3){
        int x=max(a[1],max(a[2],a[3]));
        int z=min(a[1],min(a[2],a[3]));
        int y=a[1]+a[2]+a[3]-x-z;
        if(x+y>z) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
    return 0;
}