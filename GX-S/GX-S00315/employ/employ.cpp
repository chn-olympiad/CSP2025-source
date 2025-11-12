#include<bits/stdc++.h>
#define N 501
#define mod 998244353
using namespace std;
int read()
{
  int x=0,f=1;char c=getchar();
  while(!isdigit(c))
  {
      if(c=='-') f=-1;
      c=getchar();
  }
  while(isdigit(c))
  {
      x=x*10+c-'0';
      c=getchar();
  }
  return x*f;
}
int n,m;
string s;
int a[N],d[N];
long long ans;
void dfs(int k,int num)
{
  if(k==n&&num>=m)
  {
      ans=(ans+1)%mod;
      return;
  }
  if(n-k+num<m) return;
  for(int i=1;i<=n;i++)
    if(d[i]!=1)
    {
        d[i]=1;
        if(s[k]=='0')
          dfs(k+1,num);
        else  if(k-num>=a[i]) dfs(k+1,num);
        else  dfs(k+1,num+1);
        d[i]=0;
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read(),m=read();cin>>s;
    for(int i=1;i<=n;i++)  a[i]=read();
    sort(a+1,a+n+1);
    dfs(0,0);
    printf("%lld",ans);
    return 0;
}
