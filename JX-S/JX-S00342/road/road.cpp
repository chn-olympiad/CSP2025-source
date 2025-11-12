#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL N=10005;
const LL INF=2147483647;
struct node{
    LL i,w;
    bool friend operator<(node x,node y){
        return x.w>y.w;
    }
};
LL u[N],v[N],w[N];
LL c[N];
LL a[N][N];
LL vis[N];
LL dis[N];
vector<node>t[N*10];
priority_queue<node>q;
void add(int u,int v,int w){
    node x;
    x.i=v,x.w=w;
    t[u].push_back(x);
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    LL n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i]>>w[i];
        add(u[i],v[i],w[i]);
        add(v[i],u[i],w[i]);
    }
    bool f=1;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]!=0){
            f=0;
        }
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(c[i]==0){
                add(i,j,a[i][j]);
                add(j,i,a[i][j]);
            }
        }
    }
    /*for(int i=1;i<=n;i++){
            cout<<i<<':';
        for(auto to:t[i]){
            cout<<to.i<<' '<<to.w<<"   ";
        }
    cout<<'\n';
    }*/
    if(k==0||f==1){
        LL ans=0;
        vis[1]=1;
        for(int i=1;i<=n;i++){
            dis[i]=INF;
        }
        for(auto to:t[1]){
            if(dis[to.i]>to.w){
                dis[to.i]=to.w;
                q.push(to);
            }
        }
        node x;
        while(!q.empty()){
            x=q.top();
            q.pop();
            if(vis[x.i]==1){
                continue;
            }
            vis[x.i]=1;
            /*cout<<x.w<<':';
            for(int i=1;i<=n;i++){
                cout<<vis[i]<<' '<<dis[i]<<"   ";
            }
            cout<<'\n';*/
            ans+=x.w;
            for(auto to:t[x.i]){
                if(vis[to.i]==0&&dis[to.i]>to.w){
                    dis[to.i]=to.w;
                    q.push(to);
                }
            }
        }
        cout<<ans;
        return 0;
    }
    cout<<k<<' '<<f;
    return 0;
}
