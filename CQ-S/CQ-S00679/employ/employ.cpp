#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
inline int add(int x,int y){
  int s=x+y; if(s>=P)s-=P; return s;
}
inline void self_add(int &x,int y){
  if((x+=y)>=P)x-=P;
}
int main(){
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n,m,r=0; string s; cin>>n>>m>>s;
  vector<int> c(n);
  for(auto &i:c)cin>>i;
  sort(c.begin(),c.end());
  if(n<=18){
    vector<vector<int> > f(1<<n,vector<int>(n+1));
    f[0][0]=1;
    for(int S=0;S<1<<n;S++){
      vector<int> v;
      for(int j=0;j<n;j++)
        if(!(S>>j&1))v.emplace_back(j);
      int l=__builtin_popcount(S);
      for(int j=0;j<=l;j++)
        if(f[S][j])
          for(int k:v)self_add(f[S|1<<k][j+(s[l]=='0'||j>=c[k])],f[S][j]);
    }
    for(int i=0;i<=n-m;i++)
      self_add(r,f[(1<<n)-1][i]);
  }
  else if(m==n){
    for(int i:c)if(!i)cout<<"0\n",exit(0);
    for(char i:s)if(i=='0')cout<<"0\n",exit(0);
    for(int i=r=1;i<=n;i++)
      r=1ll*r*i%P;
  }
  else if(m==1){
    vector<int> tc(n+1);
    for(int i:c)tc[i]++;
    int w=1,z=0;
    for(int i=0,t=0;i<n;i++){
      t+=tc[i];
      if(s[i]=='1')w=1ll*w*t%P,t--;
      else z++;
    }
    for(int i=1;i<=z;i++)
      w=1ll*w*i%P;
    for(int i=r=1;i<=n;i++)
      r=1ll*r*i%P;
    self_add(r,P-w);
  }
  cout<<r<<endl;
  return 0;
}