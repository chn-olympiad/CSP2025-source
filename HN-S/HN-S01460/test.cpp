#include<bits/stdc++.h>
using namespace std;
namespace FileIO{
    void Test(string s){
        freopen((s+".in").c_str(),"r",stdin);
        freopen("test.out","w",stdout);
    }
    void File(string s){
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}
int n,m,k;
int fa[10004],siz[10004];
int Find(int x){
    return fa[x]==x?x:fa[x]=Find(fa[x]);
}
void Merge(int x,int y){
    x=Find(x),y=Find(y);
    if(x==y) return ;
    if(siz[x]>siz[y]) swap(x,y);
    fa[x]=y;
    siz[y]+=siz[x];
}
struct Edge{
    int u,v,w;
    bool operator <(const Edge &p)const{
        return w<p.w;
    }
};
vector<Edge> e,te;
int c[15];
int se[15][10004];
long long val[10004];
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
void Work(){
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++){
        fa[i]=i;
        siz[i]=1;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e.push_back({u,v,w});
    }
    sort(e.begin(),e.end());
    for(int i=0;i<e.size();i++){
        if(Find(e[i].u)==Find(e[i].v)){
            continue;
        }
        Merge(e[i].u,e[i].v);
        te.push_back(e[i]);
    }
    vector<int> p(1);
    for(int i=1;i<=k;i++){
        p.push_back(i);
    }
    shuffle(next(p.begin()),p.end(),rd);
    for(int i=1;i<=k;i++){
        cin>>c[p[i]];
        for(int j=1;j<=n;j++){
            cin>>se[p[i]][j];
        }
    }
    long long ans=1e18;
    for(int state=0;state<(1<<k);state++){
        vector<Edge> tmp=te;
        for(int i=1;i<=n+k;i++){
            fa[i]=i;
            siz[i]=1;
        }
        long long tans=0;
        for(int i=1;i<=k;i++){
            if(state>>(i-1)&1){
                tans+=c[i];
                for(int j=1;j<=n;j++){
                    tmp.push_back({i+n,j,se[i][j]});
                }
            }
        }
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<tmp.size();i++){
            if(Find(tmp[i].u)==Find(tmp[i].v)) continue;
            Merge(tmp[i].u,tmp[i].v);
            tans+=tmp[i].w;
            if(tans>ans) break;
        }
        ans=min(ans,tans);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    FileIO::Test("road/road4");
    // FileIO::File("road");
    int t=1;
    // scanf("%d",&t);
    while(t--){
        Work();
    }
    clog<<clock()*1.0/CLOCKS_PER_SEC;
    return 0;
}
/*
g++ test.cpp -o test -fsanitize=address,undefined -g
g++ test.cpp -o test -O2
2 1 1
1 2 3
1 1 2

3 3 1
1 2 4
2 3 4
3 1 4
4 1 1 1
*/