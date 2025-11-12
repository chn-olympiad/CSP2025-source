#include<bits/stdc++.h>
#define N 10005
#define M 1000005
#define int long long
using namespace std;
int n,m,k,c[15],a[15][N],ans=0,fa[N];
struct node{
    int u,v,w;node(){}
    node(int uu,int vv,int ww){u=uu,v=vv,w=ww;}
    void init(){scanf("%d%d%d",&u,&v,&w);}
}T[M],E[M];
vector<int> vp;
bool cmp(node xx,node yy){return xx.w<yy.w;}
int findfa(int x){
    if(fa[x]==x)return x;
    return fa[x]=findfa(fa[x]);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++)T[i].init();
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
    }
    sort(T+1,T+m+1,cmp);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int xx=findfa(T[i].u);
        int yy=findfa(T[i].v);
        if(xx==yy)continue;
        ans+=T[i].w;fa[xx]=yy;
        vp.push_back(i);
    }
    for(int aa=0;aa<(1<<k);aa++){
        int sum=0,num=0,nm=n+k;
        for(int i=1;i<=k;i++){
            if(aa&(1<<(i-1))){
                sum+=c[i];
                for(int j=1;j<=n;j++){
                    E[++num]=node(i+n,j,a[i][j]);
                }
            }
        } if(sum>=ans)continue;
        for(int i:vp)E[++num]=T[i];
        sort(E+1,E+num+1,cmp);int bc=0;
        for(int i=1;i<=nm;i++)fa[i]=i;
        for(int i=1;i<=num;i++){
            int xx=findfa(E[i].u);
            int yy=findfa(E[i].v);
            if(xx==yy)continue;
            if(bc==nm-1)break;
            sum+=E[i].w;fa[xx]=yy;bc++;
        }ans=min(ans,sum);
    }printf("%lld",ans);return 0;
}
