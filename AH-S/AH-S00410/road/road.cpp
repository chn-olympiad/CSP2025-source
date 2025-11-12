#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int n,m,k;cin>>n>>m>>k;
    int e[n+1][n+1],len[m+1];
    memset(e,INT_MAX,sizeof(e));

    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        e[u][v]=w;
        e[v][u]=w;
        len[i]=w;
    }
    sort(len+1,len+m);
    long long ans=0;
    for(int i=1;i<n;i++){
        ans+=len[i];
    }
    return 0;
}

