#include <bits/stdc++.h>
using namespace std;
const int maxn=2000006;
#define int long long
#define mp make_pair
struct E{
    int nxt,to,w;
}e[2*maxn];
int head[maxn*2],cnt;
void add(int u,int v,int w){
    e[++cnt].w=w;
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
int n,m,k,dis[2*maxn];
bool vis[2*maxn];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[1]=0;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    int temp;
    int cnt2=n;
    for(int i=1;i<=k;i++){
        cin>>temp;
        cnt2++;
        for(int j=1;j<=n;j++){
            int w;
            cin>>w;
            add(cnt2,j,w);
            add(j,cnt2,w);
        }
    }
    q.push(mp(0,1));
    while(!q.empty()){
        pair<int,int> c=q.top();
        q.pop();
        if(vis[c.second])
            continue;
        vis[c.second]=1;
        for(int i=head[c.second];i;i=e[i].nxt){
            int v=e[i].to;
            if(dis[v]>dis[c.second]+e[i].w){
                dis[v]=dis[c.second]+e[i].w;
                q.push(mp(dis[v],v));
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=dis[i];
    }
    cout<<ans;
	return 0;
}
