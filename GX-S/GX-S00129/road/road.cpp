#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,fa[10005],wei[1000005];
struct edge{int u,v,w;}e[1000005];
bool cmp(edge a,edge b){return a.w<b.w;}
void init(){for(int i=1;i<=n;i++)fa[i]=i;}
int finds(int x){if(fa[x]!=x)fa[x]=finds(fa[x]);return fa[x];}
bool unite(int x,int y){int p=finds(x),q=finds(y);if(p==q)return 0;fa[p]=q;return 1;}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    init();
    for(int i=1;i<=m;i++){
        int x,y,z;cin>>x>>y>>z;
        e[i]={x,y,z};
    }
    int cnt=0,sum=0;
    for(int i=1;i<=k;i++){
        int nong;cin>>nong;
        for(int j=1;j<=n;j++){
            cin>>wei[j];
        }
        for(int j=1;j<=m;j++){
            e[j].w=min(e[j].w,wei[e[j].u]+wei[e[j].v]);
        }
    }
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=m;i++){
        if(unite(e[i].u,e[i].v)){
            ++cnt;
            sum+=e[i].w;
        }
        if(cnt==n-1)break;
    }
    cout<<sum;
    return 0;
}
