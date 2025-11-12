#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string st;
int c[10000];
int a[100010];
long long ans=0;
bool bo[100010];
void dfs(int u)
{
  if(u>n)
  {
   int k=0,t=0;
   for(int i=1;i<=n;i++)
   if(c[a[i]]<=k or st[i-1]-'0'==0) k++;
   else t++;
   if(t>=m) ans++;
  }
  for(int i=1;i<=n;i++)
   if(bo[i]==0) 
   {
	bo[i]=1;
	a[u]=i;
	dfs(u+1);
	bo[i]=0;
   } 
}
int main()
{
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  cin>>n>>m;
  cin>>st;
  for(int i=1;i<=n;i++) cin>>c[i];
  dfs(1);
  cout<<ans%mod;
  return 0;
}
