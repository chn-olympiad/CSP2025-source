#include<bits/stdc++.h>
using namespace std;

typedef long long i64;
const i64 N=5e5+5;
i64 a[N];
i64 n,k;
i64 xr[N];
struct line
{
  i64 l,r;
};
vector<line>g;

int main()
{
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin>>n>>k;
  for(i64 i=1;i<=n;i++)
    cin>>a[i];
  for(int i=1;i<=n;i++)
    xr[i]=xr[i-1]^a[i];
  for(int i=1;i<=n;i++)
    for(int j=i;j<=n;j++)
      if((xr[i-1]^xr[j])==k)
      g.push_back({i,j});
  sort(g.begin(),g.end(),[](line &a,line &b){return a.l<b.l;});
  i64 r=0,ans=0;
  for(auto &i:g){
    if(i.l>r){
      ans++;
      r=i.r;
    }else{
      r=min(r,i.r);
    }
  }
  cout<<ans<<endl;
  return 0;
}
