#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tpi;
class dsu{
  private:
    vector<int> f,s;
  public:
    dsu(int n):f(n),s(n,1){
      iota(f.begin(),f.end(),0);
    }
    int leader(int x){
      return x==f[x]?x:f[x]=leader(f[x]);
    }
    void merge(int u,int v){
      if((u=leader(u))==(v=leader(v)))return;
      if(s[u]>s[v])swap(u,v);
      s[v]+=s[u],f[u]=v;
    }
    bool same(int u,int v){
      return leader(u)==leader(v);
    }
};
inline bool cmp(tpi x,tpi y){
  return get<2>(x)<get<2>(y);
}
vector<tpi> mst(int n,vector<tpi> e){
  sort(e.begin(),e.end(),cmp);
  vector<tpi> ne;
  dsu d(n);
  for(auto x:e){
    int u,v,w; tie(u,v,w)=x;
    if(!d.same(u,v))ne.emplace_back(u,v,w),d.merge(u,v);
  }
  return ne;
}
ll mst2(int n,vector<tpi> &e){
  ll c=0;
  dsu d(n);
  for(auto x:e){
    int u,v,w; tie(u,v,w)=x;
    if(!d.same(u,v))c+=w,d.merge(u,v);
  }
  return c;
}
int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n,m,k; cin>>n>>m>>k;
  vector<tpi> e(m);
  for(int i=0;i<m;i++){
    int u,v,w; cin>>u>>v>>w;
    e[i]=make_tuple(--u,--v,w);
  }
  vector<int> c(k);
  vector<vector<pii> > a(k,vector<pii>(n));
  for(int i=0;i<k;i++){
    cin>>c[i];
    for(int j=0;j<n;j++)
      cin>>a[i][j].first,a[i][j].second=j;
    sort(a[i].begin(),a[i].end());
  }
  e=mst(n,e);
  ll r=6e18;
  auto dfs=[&](auto &&self,int p,int pc,ll ex)->void{
    if(p==k){r=min(r,mst2(n+pc,e)+ex); return;}
    self(self,p+1,pc,ex);
    vector<tpi> ea(n),e2(e.size()+n);
    for(int i=0;i<n;i++)
      ea[i]=make_tuple(n+pc,a[p][i].second,a[p][i].first);
    merge(ea.begin(),ea.end(),e.begin(),e.end(),e2.begin(),cmp);
    swap(e,e2);
    self(self,p+1,pc+1,ex+c[p]);
    swap(e,e2);
  };
  dfs(dfs,0,0,0),cout<<r<<endl;
  return 0;
}