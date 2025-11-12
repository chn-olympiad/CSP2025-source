#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,int> > e[11000];// to, cost
int villagecost[20];
int cost[8000][8000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    memset(cost,0x3f3f3f3f,sizeof(cost));
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
        cost[u][v]=w;
        cost[v][u]=w;
    }
    for(int j=1;j<=k;j++){
        int villagepos=n+j;
        int c;
        cin>>c;
        villagecost[villagepos]=c;
        for(int i=1;i<=n;i++){
            int cc;
            cin>>cc;
            cost[i][villagepos] = cc;
            cost[villagepos][i]=cc;
            e[villagepos].push_back({i,cc});
            e[i].push_back({villagepos,cc});

        }
    }
    for(int i=1;i<=n+k;i++){
        for(int j=1;j<=n+k;j++){
            for(int kk=1;kk<=n+k;kk++){
                cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<n;i++){
        ans+=cost[i][i+1];
    }
    cout<<ans;
    return 0;
}
