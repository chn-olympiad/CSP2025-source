#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using bian=array<int,3>;
constexpr int N=1e4+99,M=1e6+99,K=12;
#define FOR(i,l,r) for(int i=(int)(l);i<=(int)(r);++i)
int n,m,k,h;
bian yu[M];
int to[M];
int c[K];
bian a[K][N];
struct bcj{
    int fa[N],sz[N];
    void clear(){FOR(i,1,n+k)fa[i]=i,sz[i]=1;}
    int find(const int x){return (fa[x]==x)?x:(fa[x]=find(fa[x]));}
    bool merge(int x,int y){
        x=find(x),y=find(y);
        if(x==y)return 0;
        if(sz[x]>sz[y])swap(x,y);
        sz[y]+=sz[x];
        fa[x]=y;
        return 1;
    }
}bc;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    FOR(i,1,m)cin>>yu[i][1]>>yu[i][2]>>yu[i][0];
    FOR(i,1,k){
        cin>>c[i];
        FOR(j,1,n)cin>>a[i][j][0],a[i][j][1]=i+n,a[i][j][2]=j;
        sort(a[i]+1,a[i]+1+n);
        a[i][n+1][0]=1e9+7;
    }
    FOR(i,1,m)to[i]=i;
    sort(to+1,to+1+m,[&](const int x,const int y){return yu[x][0]<yu[y][0];});
    bc.clear();
    FOR(i,1,m)if(bc.merge(yu[to[i]][1],yu[to[i]][2]))a[0][++h]=yu[to[i]];
    sort(a[0]+1,a[0]+n);
    a[0][n][0]=1e9+7;
    ll ans=1e18;
    FOR(e,0,(1<<k)-1){
        ll sum(0);
        int pe(0);
        FOR(i,1,k)if(e&(1<<(i-1)))sum+=c[i],++pe;
        if(sum>=ans)continue;
        bc.clear();
        int top[]={1,1,1,1,1,1,1,1,1,1,1,1,1};
        for(int bi=1;bi<n+pe;){
            int now=0;
            FOR(j,1,k)if(e&(1<<(j-1)))if(a[now][top[now]][0]>a[j][top[j]][0])now=j;
            if(bc.merge(a[now][top[now]][1],a[now][top[now]][2])){
                sum+=a[now][top[now]][0];
                ++bi;
                if(sum>=ans)break;
            }
            ++top[now];
        }
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}
