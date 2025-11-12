#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1.1e5+5,M=1e6+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m,k,c[N],a[20][N],fa[N],tot;
ll ans=inf;
struct node{
    int u,v,w;
}g[M],e[N],t[N];

int find(int x){
    return fa[x]==x? x:fa[x]=find(fa[x]);
}
bool cmp(node x,node y){
    return x.w<y.w;
}
ll solve1(){
    int cnt=0;
    ll sum=0;
    for(int i=1;i<=m;++i){
        int u=g[i].u,v=g[i].v;
        int fu=find(u),fv=find(v);
        if(fu!=fv){
            e[++cnt]={u,v,g[i].w};
            fa[fu]=fa[fv];
            sum+=g[i].w;
        }
        if(cnt==n-1) return sum;
    }
    return sum;
}
ll solve2(int k){
    int cnt=0;
    ll sum=0;
    for(int i=1;i<=tot;++i){
        int u=t[i].u,v=t[i].v;
        int fu=find(u),fv=find(v);
        if(fu!=fv){
            ++cnt;
            fa[fu]=fa[fv];
            sum+=t[i].w;
            //cout<<u<<" "<<v<<" "<<t[i].w<<" "<<sum<<endl;
        }
        if(cnt==n+k-1) return sum;
    }
    return sum;
}

int main(){
    //freopen("road.in","w",stdout);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=m;++i) cin>>g[i].u>>g[i].v>>g[i].w;
    for(int i=1;i<=k;++i){
        cin>>c[i];
        for(int j=1;j<=n;++j) cin>>a[i][j];
    }
    sort(g+1,g+m+1,cmp);
    ans=min(ans,solve1());
    for(int s=1;s<(1<<k);++s){
        for(int i=1;i<=tot;++i) t[i]={0,0,0};
        for(int i=1;i<n;++i) t[i]=e[i];
        for(int i=1;i<=n+k;++i) fa[i]=i;
        tot=n-1;
        int cnt=0;
        ll sum=0;
        for(int i=0;i<k;++i){
            if((s>>i)&1){
                for(int j=1;j<=n;++j) t[++tot]={n+i+1,j,a[i+1][j]};
                cnt++;
                sum+=c[i+1];
                //cout<<i+1<<" "<<sum<<endl;
            }
        }
        sort(t+1,t+tot+1,cmp);
        sum+=solve2(cnt);
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}
/*
4 4 2
1 2 2
1 3 1
3 4 18
1 4 20
10 2 1 3 2
15 3 1 1 1

4 4 2
1 2 20
1 3 1
3 4 18
1 4 20
5 2 1 3 20
5 3 10 1 1
*/
