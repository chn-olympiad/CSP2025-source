#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,x,y,z,c[15],fa[10505],res=1e18;
struct edge{
    int x,y,z,tp;
    bool operator<(const edge &a)const{return z<a.z;}
}e[2000005];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>e[i].x>>e[i].y>>e[i].z,e[i].tp=0;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)cin>>z,e[++m]=(edge){j,n+i,z,i};
    }
    sort(e+1,e+m+1);
    for(int i=0;i<(1<<k);i++){
        int sum=n+__builtin_popcount(i),ans=0;
        for(int j=1;j<=n;j++)fa[j]=j;
        for(int j=1;j<=k;j++)if(i&(1<<(j-1)))fa[n+j]=n+j,ans+=c[j];
        for(int j=1;j<=m&&sum!=1;j++){
            if(e[j].tp&&!(i&(1<<(e[j].tp-1))))continue;
            int x=find(e[j].x),y=find(e[j].y),z=e[j].z;
            if(x==y)continue;
            fa[x]=y,sum--,ans+=z;
        }
        res=min(res,ans);
    }
    cout<<res;
    return 0;
}