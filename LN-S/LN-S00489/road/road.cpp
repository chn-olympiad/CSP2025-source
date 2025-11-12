#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4+9,M = 1e6+9,K = 19;
int n,m,k;
int c[K],a[K][N];
int cnt,fa[N+K];
ll Ans;
int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
struct E{int u,v,w;}e[M],MST[N];
bool cmp(E A,E B){return A.w<B.w;}
void solve(int x){
    ll Res=0ll,Ecnt=0ll;
    for(int i=1;i<n;i++){
        e[++Ecnt]=(E){MST[i].u,MST[i].v,MST[i].w};
    }
    for(int i=1;i<=k;i++){
        if((x&(1<<(i-1)))==0)continue;
        Res+=c[i];
        for(int j=1;j<=n;j++){
            e[++Ecnt]=(E){n+i,j,a[i][j]};
        }
    }
    if(Res>=Ans)return ;
    sort(e+1,e+Ecnt+1,cmp);
    int Cnt=0;
    for(int i=1;i<=n+k;i++)fa[i]=i;
    for(int i=1;i<=Ecnt;i++){
        int fu=Find(e[i].u),fv=Find(e[i].v);
        if(fu==fv)continue;
        fa[fu]=fv;
        Res+=e[i].w;
        Cnt++;
        if(Res>=Ans)return ;
        if(Cnt==n+k-1)break;
    }Ans=min(Ans,Res);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[i]=(E){u,v,w};
    }sort(e+1,e+m+1,cmp);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int fu=Find(e[i].u),fv=Find(e[i].v);
        if(fu==fv)continue;
        fa[fu]=fv;
        cnt++;
        Ans+=e[i].w;
        MST[cnt]=(E){e[i].u,e[i].v,e[i].w};
        if(cnt==n-1)break;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)cin>>a[i][j];
    }
    for(int i=1;i<(1<<k);i++){solve(i);}
    cout<<Ans<<endl;
    return 0;
}
