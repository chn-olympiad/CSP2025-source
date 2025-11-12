#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+10;
const ll inf=1e15;
const ll mod=998244353;

int n,m,t;
ll a[maxn],pick[3][maxn],kick[maxn],fa[maxn],cost[maxn],dis[20][10010];
struct node{
    int u,v;
    ll w;
}edge[maxn];

bool cmp(node a,node b){
    return a.w<b.w;
}

int find_root(int x){
    if(fa[x]==x) return x;
    return fa[x]=find_root(fa[x]);
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=m;i++){
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        edge[i]=(node){u,v,w};
    }

    int N=n;
    for(int i=1;i<=t;i++){
        scanf("%lld",&cost[i]);
        for(int j=1;j<=N;j++){
            ll v;
            scanf("%lld",&dis[i][j]);
        }
        if(!cost[i]){
            for(int j=1;j<=N;j++) edge[m+j]=(node){n+1,j,dis[i][j]};
            n++,t--,i--,m+=N;
        }
    }

    if(!t){
        //cout<<n<<" "<<m<<endl;
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
        ll ans=0;
        sort(edge+1,edge+1+m,cmp);
        for(int i=1;i<=m;i++){
            ll fu=find_root(edge[i].u),fv=find_root(edge[i].v);
            if(fu==fv) continue;
            fa[fu]=fv,ans+=edge[i].w;
        }

        printf("%lld",ans);
        fclose(stdin);
        fclose(stdout);
        return 0;
    }

    int M=m;
    ll ans1=inf;
    for(int S=0;S<(1<<t);S++){
        m=M;
        n=N;
        ll ans=0;
        for(int i=1;i<=t;i++){
            if((1<<(i-1))&S){
                ans+=cost[i];
                for(int j=1;j<=N;j++) edge[m+j]=(node){n+1,j,dis[i][j]};
                m+=N,n++;
            }
        }
        if(n-N>7) continue;

        for(int i=1;i<=n;i++){
            fa[i]=i;
        }

        sort(edge+1,edge+1+m,cmp);
        int x=n;
        for(int i=1;i<=m&&x>1;i++){
            ll fu=find_root(edge[i].u),fv=find_root(edge[i].v);
            if(fu==fv) continue;
            fa[fu]=fv,ans+=edge[i].w,x--;
        }
        ans1=min(ans1,ans);
    }

    printf("%lld",ans1);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
