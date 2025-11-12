#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1110,M=2000010;
const ll INF=1e16+10;
int n,m,k;
int cost[N][N];
int dist[N];
int w[15];
ll ans=INF;
bool st[N];
int count(int state) {
    int res=0;
    for(int i=0;i<k;i++)
        if(state>>i&1) res++;
    return res;
}
void prim(int state) {
    memset(st,0,sizeof st);
    memset(dist,0x3f,sizeof dist);
    ll res=0;
    for(int i=0;i<k;i++)
        if(state>>i&1)
            res+=w[i+1];
    dist[1]=0;
    for(int i=0;i<n+count(state);i++) {
        int t=-1;
        for(int j=1;j<=n+k;j++)
            if(st[j]==0&&(t==-1||dist[t]>dist[j])&&(j<=n||state>>(j-n-1)&1))
                t=j;
        st[t]=true;
        // cout<<t<<" ";
        res+=dist[t];
        for(int j=1;j<=n+k;j++) {
            if((j>n&&state>>(j-n-1)&1)||(j<=n)) {
                dist[j]=min(dist[j],cost[t][j]);
                // cout<<dist[j];
            }
        }
    }
    ans=min(ans,res);
}
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);

    memset(cost,0x3f,sizeof cost);
    for(int i=1;i<=m;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        cost[a][b]=cost[b][a]=min(cost[a][b],c);
    }

    for(int i=n+1;i<=n+k;i++) {
        scanf("%d",&w[i-n]);
        for(int j=1;j<=n;j++) {
            int c;
            scanf("%d",&c);
            cost[i][j]=cost[j][i]=min(cost[i][j],c);
        }
    }

    for(int t=0;t<1<<k;t++) {
        prim(t);
    }
    printf("%lld\n",ans);

    return 0;
}

