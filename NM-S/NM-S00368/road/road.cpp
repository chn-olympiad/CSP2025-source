#include <bits/stdc++.h>
using namespace std;
const int N=1e4+15;
int n,m,k;
int to[N][N];
int vills[N];
int sett[N];
struct Edge{
    int u,v,w;
}edge[N*N/2];
inline bool cmp(Edge x,Edge y){
    return x.w<y.w;
}
inline void init(){
    for(register int i=1;i<=n+k;i++)sett[i]=i;
}
inline int f_fa(int x){
    if(sett[x]!=x){
        int pa=f_fa(sett[x]);
        sett[x]=pa;
        return sett[x];
    }
    return x;
}
inline long long kls(int vil,int cnt,int cnt1){
    long long res=0;
    int cntt=0;
    for(register int i=1;i<=cnt;i++){
        if((edge[i].u>n)&&!(vil&(1<<(edge[i].u-n-1))))continue;
        if((edge[i].v>n)&&!(vil&(1<<(edge[i].v-n-1))))continue;
        int a=f_fa(edge[i].u),b=f_fa(edge[i].v);
        if(a!=b){
            res+=edge[i].w;
            cntt++;
            sett[a]=b;
        }
        if(edge[i].w>(int)1e9)return 1e18;
        if(cntt==n+cnt1-1)return res;
    }
    return 1e18;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    memset(to,0x3f,sizeof to);
    //for(int i=1;i<=n*n/2;i++)pm[i]=i;
    for(register int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(u>v)swap(u,v);
        to[u][v]=min(to[u][v],w);
    }
    for(register int i=1;i<=k;i++){
        scanf("%d",&vills[i]);
        for(int j=1;j<=n;j++){
            int w;
            scanf("%d",&w);
            to[j][n+i]=min(to[j][n+i],w);
        }
    }
    int cnt=0;
    for(register int i=1;i<=n+k;i++){
        for(int j=i+1;j<=n+k;j++){
            edge[++cnt]={i,j,to[i][j]};
        }
    }
    sort(edge+1,edge+1+cnt,cmp);
    //for(int i=1;i<=cnt;i++)cout<<edge[i].w<<" ";
    long long ans=1e18;
    for(register int i=0;i<=(1<<k)-1;i++){
        long long ans1=0;
        int cnt1=0;
        for(int j=1;j<=k;j++){
            if(i&(1<<(j-1)))ans1+=vills[j],cnt1++;
        }
        init();
        ans1+=kls(i,cnt,cnt1);
        //printf("%lld\n",ans1);
        ans=min(ans,ans1);
    }
    printf("%lld",ans);
	return 0;
}
