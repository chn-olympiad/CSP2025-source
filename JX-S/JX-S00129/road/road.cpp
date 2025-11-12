#include<bits/stdc++.h>
#define int long long
using std::cin;
using std::cout;
using std::min;
using std::max;
using std::sort;
using std::memset;
using std::vector;
using std::set;
using std::ios;

int n,m,k,p,cnt;
struct edge{
  int u,v,w;
  bool operator <(const edge b)const{
    return w<b.w;
  }
}a[1000005],b[1000005];
int f[1000005];
int find(int u){
  if (f[u]==u)return u;
  return f[u]=find(f[u]);
}
int g[11][10005];
void solve(){
  p=0;
  cin>>n>>m>>k;
  for (int i=1;i<=n;i++)f[i]=i;
  for (int i=1;i<=m;i++){
    cin>>a[i].u>>a[i].v>>a[i].w;
  }
  sort(a+1,a+1+m);
  int ans=0;
  for (int i=1;i<=m;i++){
    int u=a[i].u,v=a[i].v;
    if (find(u)!=find(v)){
	f[find(u)]=find(v);
	ans+=a[i].w;
	b[++p]=a[i];
    }
  }
  for (int i=1;i<=k;i++){
    cin>>g[i][0];
    for (int j=1;j<=n;j++){
      cin>>g[i][j];
      b[++p].u=i+n;
      b[p].v=j;
      b[p].w=g[i][j];
    }
  }
  sort(b+1,b+1+p);
  for (int i=1;i<(1<<k);i++){
    int res=0,cnt=n-1;
    for (int j=1;j<=k;j++){
      if (i&(1<<j-1))res+=g[j][0],++cnt;
    }
    for (int j=1;j<=n+k;j++)f[j]=j;
    for (int j=1;j<=p;j++){
      int u=b[j].u,v=b[j].v;
      if (u>n&&!(i&(1<<u-n-1)))continue;
      if (find(u)!=find(v)){
	f[find(u)]=find(v);
	res+=b[j].w;
	--cnt;
	if (!cnt)break;
      }
    }
    ans=min(ans,res);
  }
  cout<<ans<<"\n";
}
signed main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solve();
  return 0;
}
