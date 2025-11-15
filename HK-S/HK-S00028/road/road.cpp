#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
#define rep(x,y,z) for (int x=y;x<z;x++)
#define cin fin
#define cout fout
ifstream fin("road.in");
ofstream fout("road.out");
struct edge{ int u; int v; int w;};

bool com(const edge &a, const edge &b){
  return a.w<b.w;
}

int par(int x, vector<int> &dsu){
  if (dsu[x]<0) return x;
  return dsu[x]=par(dsu[x],dsu);
}

vector<edge> old(100000);

int kru(vector<edge> &vec, vector<edge> &add, int n, bool o){
  int cnt=n-1;
  vector<int> dsu(n,-1);
  int res=0;
  int m=vec.size(),k=add.size();
  int i=0,j=0;
  while (i<m&&j<k){
    int ca,cb,cw;
    if (vec[i].w<add[j].w){
      ca=vec[i].u;
      cb=vec[i].v;
      cw=vec[i].w;
      i++;
    }else{
      ca=add[j].u;
      cb=add[j].v;
      cw=add[j].w;
      j++;
    }
    int pa=par(ca,dsu);
    int pb=par(cb,dsu);
    if (pa!=pb){
      res+=cw;
      dsu[pa]=pb;
      cnt--;
      if (o) old[cnt-1]={ca,cb,cw};
      if (!cnt) return res;
    }
  }
  while (i<m){
    int ca,cb,cw;
    ca=vec[i].u;
    cb=vec[i].v;
    cw=vec[i].w;
    i++;
    int pa=par(ca,dsu);
    int pb=par(cb,dsu);
    if (pa!=pb){
      res+=cw;
      dsu[pa]=pb;
      cnt--;
      if (o) old[cnt-1]={ca,cb,cw};
      if (!cnt) return res;
    }
  }
  while (j<k){
    int ca,cb,cw;
    ca=add[j].u;
    cb=add[j].v;
    cw=add[j].w;
    j++;
    int pa=par(ca,dsu);
    int pb=par(cb,dsu);
    if (pa!=pb){
      res+=cw;
      dsu[pa]=pb;
      cnt--;
      if (o) old[cnt-1]={ca,cb,cw};
      if (!cnt) return res;
    }
  }
  return res;
}

signed main(){
  cin.tie(nullptr)->ios::sync_with_stdio(0);
  int n,m,k;
  cin>>n>>m>>k;
  vector<edge> vec(m);
  rep(i,0,m){
    int ca,cb,cw;
    cin>>ca>>cb>>cw;
    ca--; cb--;
    vec[i]={ca,cb,cw};
  }
  sort(all(vec),com);
  vector<int> cost(k);
  int arr[k][n];
  rep(i,0,k){
    cin>>cost[i];
    rep(j,0,n){
      cin>>arr[i][j];
    }
  }
  int ful=(1<<k);
  vector<edge> emp;
  int ans=kru(vec,emp,n,1);
  old.resize(n-1);
  sort(all(old),com);
  rep(i,1,ful){
    int sum=0;
    int cnt=0;
    rep(j,0,k){
      if (i&(1<<j)){
        cnt++;
        sum+=cost[j];
      }
    }
    vector<edge> add(n*cnt);
    int idx=0;
    int no=0;
    rep(j,0,k){
      if (i&(1<<j)){
        rep(h,0,n){
          add[idx++]={n+no,h,arr[j][h]};
        }
        no++;
      }
    }
    sort(all(add),com);
    sum+=kru(vec,add,n+cnt,0);
    ans=min(ans,sum);
  }
  cout<<ans<<'\n';
  return 0;
}