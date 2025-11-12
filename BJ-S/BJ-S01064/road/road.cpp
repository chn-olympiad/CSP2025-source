#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int c[15],a[15][10015];
struct edge{
    int x,y,w;
    bool operator<(const edge a)const{
        return w==a.w?x==a.x?y<a.y:x<a.x:w<a.w;
    }
};
set<edge> E;
int fa[10015],sz[10015];
void init(){
    for(int i=0;i<10015;i++)fa[i]=i;
    for(int i=0;i<10015;i++)sz[i]=i;
}
int find(int x){
    return (x==fa[x]?x:fa[x]=find(fa[x]));
}
void uni(int x,int y){
    x=find(x),y=find(y);
    if(x^y){
        if(sz[x]>sz[y])fa[y]=x,sz[x]+=sz[y];
        else fa[x]=y,sz[y]+=sz[x];
    }
}
vector<pair<int,int> > g[10015];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
bool vis[10015];
int Prim(int x){
    memset(vis,0,sizeof(vis));
    q.push(make_pair(0,x));
    int ans=0;
    while(!q.empty()){
        auto ttmp=q.top();
        q.pop();
        int f=ttmp.second,w=ttmp.first;
        if(vis[f])continue;
        //cout<<"get:("<<f<<','<<w<<")\n";
        vis[f]=true;
        ans+=w;
        for(auto t:g[f]){
            //cout<<"\twant:("<<t.first<<','<<t.second<<")\n";
            if(!vis[t.first]){
                q.push(make_pair(t.second,t.first));
            }
        }
    }
    return ans;
}
int Kruskal(int nn){
    init();
    int ans=0,cc=nn;
    for(auto e:E){
        if(find(e.x)!=find(e.y)){
            cc--;
            ans+=e.w;
            uni(e.x,e.y);
            if(cc==1){
                return ans;
            }
        }
    }
    return ans;
}
namespace A{
    void solve(){
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                E.insert({n+i,j,a[i][j]});
            }
        }
        cout<<Kruskal(n);
        return;
    }
}
namespace R{
    void solve(){
        int ret=2147483647;
        for(int state=0;state<(1<<k);state++){
            int base=0;
            int num=0;
            for(int i=1;i<=k;i++){
                if((state>>(i-1))&1){
                    num++;
                    base+=c[i];
                    for(int j=1;j<=n;j++){
                        E.insert({n+i,j,a[i][j]});
                    }
                }
            }
            ret=min(ret,base+Kruskal(n+num));
            for(int i=1;i<=k;i++){
                if((state>>(i-1))&1){
                    for(int j=1;j<=n;j++){
                        E.erase(E.find({n+i,j,a[i][j]}));
                    }
                }
            }
            //cout<<"E:\n";
            //for(auto e:E){
            //    cout<<"{"<<e.x<<","<<e.y<<","<<e.w<<"}\n";
            //}
        }
        cout<<ret;
        return;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    bool hA=true;
    for(int i=1;i<=m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        //g[x].emplace_back(make_pair(y,w));
        //g[y].emplace_back(make_pair(x,w));
        E.insert({x,y,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i])hA=false;
        bool flag=false;
        for(int j=1;j<=n;j++){cin>>a[i][j];if(a[i][j]==0)flag=true;}
        hA&=flag;
    }
    if(hA)A::solve();
    else R::solve();
    return 0;
}