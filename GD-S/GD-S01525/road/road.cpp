#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int, long long> > >e(10015);
struct P{long long c,a[10005];}p[15];
struct QE{long long u,v,w;bool operator<(const QE&rhs)const{return w<rhs.w;}};
long long n,m,k,as=1e13,fa[10015];
bool dbg=0;
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
void mrg(int u,int v){u=find(u),v=find(v);if(u!=v)fa[u]=v;}
long long mc(vector<vector<pair<int,long long> > >evca,long long b,int k){
    vector<QE>q;
    for(int i=1;i<=10000+k;++i)for(auto it:e[i])q.push_back({i,it.first,it.second});
    sort(q.begin(),q.end());
    int conn=0,it=0;for(int i=1;i<=10000+k;++i)fa[i]=i;
    while(conn<n+k-1&&b<as&&it<q.size()){
        QE edg=q[it++];
        if(find(edg.u)==find(edg.v))continue;
        mrg(edg.u,edg.v);
        ++conn;
        b+=edg.w;
    }
    return b;
}
void ae(int u,int v,long long w,vector<vector<pair<int,long long> > >&e=e){
    e[u].push_back({v,w});
    e[v].push_back({u,w});
}
int main(){
#ifndef ASTRALFLARE_CE
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
#endif
    cin.tie(0)->sync_with_stdio(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        ae(u,v,w);
    }
    for(int i=1;i<=k;++i){
        cin>>p[i].c;
        for(int j=1;j<=n;++j)cin>>p[i].a[j];
    }
    for(int _pl=0;_pl<(1<<k);++_pl){
        vector<vector<pair<int,long long> > >pe=e;
        int b=0,kk=0;
        for(int i=1;i<=k;++i){
            if(!(_pl&(1<<i-1)))continue;
            ++kk;
            b+=p[i].c;
            for(int j=1;j<=n;++j)ae(10000+i,j,p[i].a[j],pe);
        }
        as=min(as,mc(pe,b,kk));
        cout<<_pl<<" COMPLETE!"<<endl;
    }
    cout<<as;
}