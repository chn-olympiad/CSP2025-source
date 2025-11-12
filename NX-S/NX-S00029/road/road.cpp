#include <bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,c[100006],a[100006],ans=0;
struct AAAAA{
    long long to,s;
};
AAAAA R[100006];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>u>>v>>w,ans+=w;
    for(int i=1;i<=k;i++) cin>>c[i]>>a[i];
    cout<<ans;
}
