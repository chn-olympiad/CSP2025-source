#include<bits/stdc++.h>
using namespace std;
#define Open(x) FILE *filein=freopen(#x".in","r",stdin),*fileout=freopen(#x".out","w",stdout);
#define int long long
const signed N=200005;
int n,m,a[N],id[N],ans,c[N];
char ch[N];
signed main(){
  Open(employ);
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>ch[i];
  for(int i=1;i<=n;i++)cin>>a[i],id[i]=i;
  do{
    for(int i=1;i<=n;i++)c[i]=c[i-1]+(ch[i]=='0'||c[i-1]>=a[id[i]]);
    if(c[n]<=n-m)ans++;
  }while(next_permutation(id+1,id+n+1));
  cout<<ans<<'\n';
  return 0;
}
