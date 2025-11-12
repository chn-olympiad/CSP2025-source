#include<bits/stdc++.h>
#define N 2000005
#define ll long long
using namespace std;

struct edge{
    int x,y;
    int z;
}e[N],e2[N],e3[N];
vector<int>G2[N];
int cpt;
bool vis[15];
ll ans;
int n,m,k,fa[N];
int m2;
int rt[15][N],c[N];
bool cmp(edge x,edge y){
    return x.z<y.z;
}
int findrt(int x){
    if(fa[x]==x)return x;
    return fa[x]=findrt(fa[x]);
}
ll MST(int n,int m){
    cpt=0;
    ll ans=0;
    int cnt=0;
    for(int i=1;i<=n;i++)fa[i]=i;
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;i++){
        int x=findrt(e[i].x);
        int y=findrt(e[i].y);
        int z=e[i].z;
        if(x==y)continue;
        fa[x]=y;
        e2[++cpt].x=e[i].x;
        e2[cpt].y=e[i].y;
        e2[cpt].z=e[i].z;
        ans+=z*1ll;
        cnt++;
        if(cnt==n-1)break;
    }
    if(cnt<n-1)return 1e18;
    return ans;
}
void copyto(){
    for(int i=1;i<=cpt;i++)e[i]=e2[i];
    m=cpt;
}
void backto(){
    for(int i=1;i<n;i++)e[i]=e3[i];
    if(k<=3)m2=m;
    else m=n-1;
}
void dfs(int x){ 
    if(x>k){
        int sum=0;
        for(int i=k;i;i--){
            sum+=vis[i];
            if(!sum)return;
        }
        backto();
        ll tot=0;
        for(int i=1;i<=k;i++){
            if(vis[i]){
                tot+=c[i]*1ll;
                for(int j=1;j<=n;j++){
                    e[++m].x=1+n;
                    e[m].y=j;
                    e[m].z=rt[i][j];
                }
                ll val=1ll*tot+MST(n+1,m);
                ans=min(ans,val);
                copyto();
            }
        }
        return;
    }
    vis[x]=0;
    dfs(x+1);
    vis[x]=1;
    dfs(x+1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
    for(int i=1;i<=k;i++){
        scanf("%d",c+i);
        for(int j=1;j<=n;j++){
            scanf("%d",rt[i]+j);
        }
    }
    ans=MST(n,m);
    copyto();
    for(int i=1;i<n;i++)e3[i]=e[i];
    m=n-1;
    if(k<=3){
        for(int i=1;i<=m;i++)e3[i]=e[i];
        m2=m;
    }
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}
/*
1 4 6
2 3 7
4 2 5
4 3 4
*/