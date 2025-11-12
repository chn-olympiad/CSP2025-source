#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[100001],v[100001],w[100001],a[100001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>u[i]>>v[i]>>w[i];
    for(int i=1;i<=k*(n+1);i++)
        cin>>a[i];
    sort(w+1,w+m+1);
    int ans=0;
    for(int i=1;i<=n-1;i++)
    {
        ans+=w[i];
    }
    cout<<ans;
    return 0;
}
