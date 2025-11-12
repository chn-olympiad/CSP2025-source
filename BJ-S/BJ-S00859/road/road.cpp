#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000000],v[1000000],w[1000000],c[10000],wulu[5000],sum=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
    sort(w+1,w+m+1);
    for(int i=1;i<=n-1;i++){
        c[u[i]]=1,c[v[i]]=1;
        sum+=w[i];
    }
    cout<<sum;
    return 0;
}
