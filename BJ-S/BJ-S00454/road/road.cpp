#include<bits/stdc++.h>
using namespace std;
struct edge{
    long long u,v,w;
    bool operator < (const edge &a)const{
        return a.w<w;
    }
}a[2000005];
struct node{
    long long v,w;
};
long long T,n,m,ans,cnt,k,f[100005],t1,t2,t3,nt,ll,c[15],vis[16],anss=1e18;
long long find(long long x){
    if(f[x]==x){
        return x;
    }
    return f[x]=find(f[x]);
}
void merge(long long x,long long y){
    f[find(x)]=find(y);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++){
        scanf("%lld%lld%lld",&t1,&t2,&t3);
        a[++cnt]={t1,t2,t3};
    }
    for(long long i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(long long j=1;j<=n;j++){
            scanf("%lld",&t1);
            a[++cnt]={n+i,j,t1};
        }
    }
    sort(a+1,a+cnt+1);
    for(long long l=0;l<=(1<<k);l++){
    ans=0;
    memset(vis,0,sizeof(vis));
    long long lt=l,opp=0;
    while(lt){
        vis[++opp]=lt%2;
        ans+=c[opp]*vis[opp];
        lt/=2;
    }
    ll=0;
    for(long long i=1;i<=n+k;i++){
        f[i]=i;
    }
    for(long long i=1;i<=cnt;i++){
        if(find(a[i].u)!=find(a[i].v)&&(a[i].u<=n||vis[a[i].u-n])&&(a[i].v<=n||vis[a[i].v-n])){
        merge(a[i].u,a[i].v);
        ans+=a[i].w;
        ll++;
        }
    }
    anss=min(ans,anss);
    }
    cout<<anss<<endl;
    return 0;
}
