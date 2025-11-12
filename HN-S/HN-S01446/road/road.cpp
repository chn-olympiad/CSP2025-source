#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+15;
int n,m,k;
int fa[N];
int a[15][N],dp[N];
int c[15];
int cnt[N],cc;
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
struct node{
    int u,v,val;
}G[N],g[N*2],nb[N];
bool cmp(node a,node b){
    return a.val<b.val;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        cin >> G[i].u >> G[i].v >> G[i].val;
    }
    sort(G+1,G+1+m,cmp);
    for(int i=1;i<=k;i++){
        cin >> c[i];
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    int ans=LLONG_MAX,cntt=0;
    for(int len=0;len<=k;len++){
        for(int id=0;id<=(1<<k)-1;id++){
            int res=0,ll=0;
            bool flag=0;
            for(int i=1;i<=k;i++){
                if((1<<i-1)&id)ll++;
            }
            if(ll!=len)continue;
            for(int i=1;i<=cc;i++){
                if((id&cnt[cc])==id){
                    flag=1;
                    break;
                }
            }
            if(flag)continue;
            cntt++;
            for(int i=1;i<=n+11;i++){
                fa[i]=i;
            }
            int len=0;
            for(int i=1;i<=k;i++){
                if((1<<i-1)&id){
                    res+=c[i];
                    for(int j=1;j<=n;j++){
                        // if(i==j)continue;
                        nb[++len]={i+n,j,a[i][j]};
                    }
                }
            }
            sort(nb+1,nb+1+len,cmp);
            int tot=0;
            int l=1,r=1;
            while(l<=m||r<=len){
                if(l>m){
                    g[++tot]=nb[r++];
                }else if(r>len){
                    g[++tot]=G[l++];
                }else{
                    if(cmp(G[l],nb[r])){
                        g[++tot]=G[l++];
                    }else{
                        g[++tot]=nb[r++];
                    }
                }
            }
            for(int i=1;i<=tot;i++){
                if(find(g[i].u)==find(g[i].v))continue;
                fa[find(g[i].u)]=find(g[i].v);
                res+=g[i].val;
                // cout << g[i].u << ' ' << g[i].v << '\n';
                // cout << g[i].val << '\n';
            }
            // cout << id << ' ' << res << '\n';
            if(len&&dp[len-1]<res){
                cnt[++cc]=ans;
                // cerr<<1;
            }
            ans=min(ans,res);
        }
        dp[len]=ans;
    }
    // cout << cntt << '\n';
    cout << dp[k] << '\n';
    return 0;
}