#include<bits/stdc++.h>
#define llong long long
using namespace std;
const llong maxn=(1e4+100)*5,maxm=(1e6*2+5)*4,INF=1e18;
llong n,m,k,fa[maxn];
llong a[15][maxn],c[maxn],add[15],q[maxn],answer=INF;
bool vis[maxn],choose[15];
vector <pair<llong,llong> > node[maxn];
struct e{
    llong u,v,w;
    friend bool operator < (e x,e y){
        return x.w<y.w;
    }
}edge[maxm];
llong getfa(llong x){
    if(x==fa[x]) return x;
    else return fa[x]=getfa(fa[x]);
}
llong kruskal(){
    llong ans=0;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    sort(edge+1,edge+m+1);
    for(int i=1;i<=m;i++){
        llong x=getfa(edge[i].u),y=getfa(edge[i].v);
        if(x==y) continue;
        ans+=edge[i].w;
        fa[x]=y;
    }
    return ans;
}
llong prim(){//vis=0 -> T,vis=1 -> S
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n;i++)
        q[i]=INF;
    llong ans=0,tot=0;
    vis[1]=1;
    for(auto [v,w]:node[1])
        q[v]=min(q[v],w);
    for(int i=1;i<=n;i++){
        llong u=0;
        for(int j=1;j<=n;j++)
            if(q[j]<q[u]&&vis[j]==0)
                u=j;
        if(u==0) break;
        vis[u]=1;
        ans+=q[u];
        for(auto [v,w]:node[u])
            q[v]=min(q[v],w);
    }
    return ans;
}
void dfs(llong p){
    if(p==k+1){
        llong sum=0,r[15],addd=0;
        for(int i=1;i<=k;i++)
            if(choose[i]){
                sum++;
                addd+=c[i];
                r[sum]=i;
            }
        for(int i=1;i<=sum;i++){
            llong u=r[i];
            for(llong v=1;v<=n;v++){
                node[n+i].push_back({v,a[u][v]});
                node[v].push_back({n+i,a[u][v]});
                edge[++m]={n+i,v,a[u][v]};
            }
        }
        bool f;
        if(m<=200000) f=1;
        else if(n*n<=3000000) f=0;
        else f=1;
        n+=sum;
        llong anss=0;
        if(f==0)
            anss=prim()+addd;
        else
            anss=kruskal()+addd;
        answer=min(answer,anss);
        /*if(prim()==505348760){
            for(int i=1;i<=k;i++)
                cout<<choose[i]<<' ';
            cout<<endl;
        }*/
        /*if(anss==5004991011)
        if(choose[1]==1&&choose[2]==0){
            for(int i=1;i<=n;i++)
                for(auto [v,w]:node[i])
                    cout<<i<<' '<<v<<endl;
            cout<<answer<<endl;
            }*/
        n-=sum;
        for(int i=1;i<=sum;i++)
            node[i+n].clear();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=sum;j++)
                node[i].pop_back();
        /*if(choose[1]==1&&choose[2]==0){
            for(int i=1;i<=n;i++)
                for(auto [v,w]:node[i])
                    cout<<i<<' '<<v<<endl;
            cout<<answer<<endl;
            }*/
        m-=n*sum;
        return;
    }
    choose[p]=0;
    dfs(p+1);
    choose[p]=1;
    dfs(p+1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    bool A=1;
    cin>>n>>m>>k;
    llong u,v,w;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&u,&v,&w);
        node[u].push_back({v,w});
        node[v].push_back({u,w});
        edge[i].u=u,edge[i].v=v,edge[i].w=w;
    }
    if(k==0){
        cout<<kruskal();
        return 0;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        llong PA=0;
        for(int j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
            if(a[i][j]==0) PA=j;
        }
        if(c[i]!=0) A=0;
        if(PA==0) A=0;
        add[i]=PA;
    }
    if(A==1){
        for(int i=1;i<=k;i++){
            llong u=add[i];
            for(int v=1;v<=n;v++){
                if(u==v) continue;
                llong w=a[i][v];
                edge[++m]={u,v,w};
                node[u].push_back({v,w});
                node[v].push_back({u,w});
            }
        }
        cout<<kruskal();
        return 0;
    }
    dfs(1);
    cout<<answer;
    return 0;
}
// 15:50 48pts
//???
