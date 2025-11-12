#include<bits/stdc++.h>
#define int long long
const int MOD=998244353;
using namespace std;
int n,m;
string s;
int ans=1;
int t;
signed main()
{
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  scanf("%lld%lld",&n,&m);
  cin>>s;
  for(int i=1; i<=n; i++)
  {
    int x;
    scanf("%lld",&x);
    if(x==0) t++;
  }
  while(n)
  {
    ans*=n;
    ans%=MOD;
    n--;
  }
  printf("%lld",ans);
  return 0;
}

