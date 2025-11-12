#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr first
#define sc second
#define pii pair<int,int>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define ro(i,r,l) for(inr i=r;i>=l;i--)
const int N=1e4+25,K=15;
int n,m,k,c[K],a[K][N];
struct edge{
    int u,v,w;
    bool operator<(edge x)const{
        return w<x.w;
    }
};
vector<edge>e,re;
namespace dsu{
    int fa[N];
    int find(int x){
        if (fa[x]==x)
            return x;
        return fa[x]=find(fa[x]);
    }
    void merge(int x,int y){
        x=find(x),y=find(y);
        if (x!=y) fa[x]=y;
    }
}
using namespace dsu;
int kruskal(int op=0){
    fo(i,1,n+k)
        fa[i]=i;
    sort(e.begin(),e.end());
    int rs=0;
    for (auto i:e){
        int u=i.u,v=i.v,w=i.w;
        int fu=find(u),fv=find(v);
        if (fu==fv)
            continue;
        merge(u,v),rs+=w;
        if (op)
            re.push_back({u,v,w});
    }
    return rs;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    fo(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        e.push_back((edge){u,v,w});
    }
    kruskal(1);
    fo(i,1,k){
        cin>>c[i];
        fo(j,1,n)
            cin>>a[i][j];
    }
    int rs=1e18;
    fo(i,0,(1ll<<k)-1){
        int s=0;
        e=re;
        fo(j,1,k)
            if ((i>>(j-1))&1){
                s+=c[j];
                fo(t,1,n)
                    e.push_back((edge){j+n,t,a[j][t]});
            }
        s+=kruskal();
        rs=min(rs,s);
    }
    cout<<rs<<'\n';
    return 0;
}
/*
o o ae ae o a i o o ai
*/