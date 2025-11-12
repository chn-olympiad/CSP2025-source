#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ep emplace
#define eb emplace_back
#define fr(a,b,c) for(int (a) = (b);(a) <= (c);a ++) 
using namespace std;
const int M = 1500000,K = 15,N = 100100;
struct node{
  int u,v,w;
};
int n,m,k,c[K],a[K][N],f[N],cnt,pcnt,cnting;
ll ans = 1e18,cst;
node e[M],g[M],tmp[N];
int find(int x){return x == f[x] ? x : f[x] = find(f[x]);}
int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  fr(i,1,m) cin >> e[i].u >> e[i].v >> e[i].w;
  fr(i,1,k){
    cin >> c[i];
    fr(j,1,n) cin >> a[i][j];
  }
  sort(e + 1,e + m + 1,[](node a,node b){
    return a.w < b.w;
  });
  iota(f + 1,f + n + 1,1);
  fr(i,1,m){
    auto [u,v,w] = e[i];
    if(find(u) == find(v)) continue;
    f[find(u)] = find(v);
    tmp[++ cnt] = e[i];
  }
  fr(i,0,(1 << k) - 1){
    fr(i,1,cnt) g[i] = tmp[i];
    cnt = n - 1,pcnt = n,cst = cnting = 0;
    fr(j,1,k){
      if(i & (1 << j - 1)){
        pcnt ++,cst += c[j];
        fr(k,1,n) g[++ cnt] = {k,pcnt,a[j][k]};
      }
    }
    iota(f + 1,f + pcnt + 1,1);
    sort(g + 1,g + cnt + 1,[](node a,node b){
      return a.w < b.w;
    });
    fr(i,1,cnt){
      auto [u,v,w] = g[i];
      if(find(u) == find(v)) continue;
      f[find(u)] = find(v),cst += w;
      if(++ cnting == pcnt - 1) break;
    }
    ans = min(ans,cst);
  }
  printf("%lld\n",ans);
  return 0;
}