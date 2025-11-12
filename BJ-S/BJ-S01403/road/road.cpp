#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+1e5+7+6;
const int maxm=1e4+1e2+5+3;
int n,m,k;
vector<pair<int,int> >g[maxm];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    /*cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(v,w);
        g[v].push_back(u,w);
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            int w;cin>>w;
            g[n+i].push_back(j,w);
            g[j].push_back(n+i,w);
        }
    }*/
    srand(time(0));cout<<rand()+rand();
    return 0;
}

