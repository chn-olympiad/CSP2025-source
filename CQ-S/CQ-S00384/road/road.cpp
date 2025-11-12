#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX=1e4+20,NAX=1.1e6+10,mod=1e9+7;
int n,m,k,all;
ll c[MAX],a;
struct road{
    int u,v;
    ll w;
    bool operator<(const road &other)const{return w<other.w;}
}roads[NAX];
vector<pair<int,ll> > tree[MAX];
int father[MAX],num;
int found(int x){
    int &fx=father[x];
    return fx==x?x:fx=found(fx);
}
int Min(int l,int r){
    int ret=-1,Min=2e9;
    for(int i=l;i<=r;i++){
        if(roads[i].w<Min){
            Min=roads[i].w;
            ret=i;
        }
    }return ret;
}
ll ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%lld",&roads[i].u,&roads[i].v,&roads[i].w);}
    for(int i=1;i<=k;i++){
        scanf("%lld",c+i);
        for(int j=1;j<=n;j++){
            scanf("%lld",&a);
            int now=m+(i-1)*n+j;
            roads[now]={n+i,j,a};
        }
        roads[Min(m+(i-1)*n+1,m+i*n)].w+=c[i];
    }
    all=m+k*n;
    // cout << all << '\n';
    sort(roads+1,roads+1+all);
    for(int i=1;i<=n+k;i++){father[i]=i;}
    num=n+k;
    for(int i=1;i<=all;i++){
        int u=roads[i].u,v=roads[i].v,w=roads[i].w;
        int fu=found(u),fv=found(v);
        if(fu!=fv){
            num--;
            father[fu]=fv;
            ans+=w;
            tree[u].emplace_back(v,w);
            tree[v].emplace_back(u,w);
        }
    }
    // printf("%lld\n",ans);
    for(int i=n+1;i<=n+k;i++){
        if(tree[i].size()==1){
            ans-=tree[i][0].second;}
    }
    printf("%lld",ans);
    return 0;
}