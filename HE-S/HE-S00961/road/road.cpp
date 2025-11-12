#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e4+15,M=1e6+5;
const int K=10;
const int inf=1e9+7;
int n,m,k;
struct edge{
    int u,v,w;
}e[M];
int c[K];
pair<int,int> ke[K][N];
int fa[N+K],si[N+K];
ll ans;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=0;i<k;++i){
        cin>>c[i];
        for(int j=1;j<=n;++j){
            cin>>ke[i][j].first;
            ke[i][j].second=j;
        }
        sort(ke[i]+1,ke[i]+n+1);
    }
    sort(e+1,e+m+1,[](const edge& x,const edge& y){
        return x.w<y.w;
    });
    ans=0;
    int cn=0;
    for(int i=1;i<=n;++i)fa[i]=i;
    for(int i=1;i<=m;++i){
        if(find(e[i].u)==find(e[i].v))continue;
        fa[find(e[i].u)]=e[i].v;
        ans+=e[i].w;
        e[++cn]=e[i];
    }
    m=cn;
    for(int z=1;z<(1<<k);++z){
        ll sum=0;
        int no=0;
        vector<int> kid,nid;
        for(int i=0;i<k;++i){
            if(z&(1<<i)){
                sum+=c[i];
                kid.push_back(i);
                nid.push_back(0);
            }
        }
        const int ndc=n+kid.size();
        for(int i=1;i<=n+k;++i){
            fa[i]=i,si[i]=1;
        }
        int ncn=0;
        while(ncn<ndc-1){
            int miv=inf;
            int noi=0;
            if(no!=m){
                miv=e[no+1].w;
                noi=-1;
            }
            for(int i=0;i<kid.size();++i){
                if(nid[i]!=n&&ke[kid[i]][nid[i]+1].first<miv){
                    miv=ke[kid[i]][nid[i]+1].first;
                    noi=i;
                }
            }
            int u,v,w=miv;
            if(noi==-1){
                u=e[no+1].u,v=e[no+1].v;
                ++no;
            }
            else{
                u=ke[kid[noi]][nid[noi]+1].second;
                v=n+1+kid[noi];
                ++nid[noi];
            }
            if(find(u)==find(v))continue;
            u=find(u),v=find(v);
            if(si[u]>si[v]){
                si[u]+=si[v];
                fa[v]=u;
            }
            else{
                si[v]+=si[u];
                fa[u]=v;
            }
            sum+=miv;
            ++ncn;
            if(sum>=ans)break;
        }
        ans=min(ans,sum);
    }
    cout<<ans<<'\n';
    return 0;
}
/*
g++ -o road road.cpp -O2 -std=c++14 && time ./road
*/