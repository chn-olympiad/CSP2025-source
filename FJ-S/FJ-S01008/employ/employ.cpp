#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,t[600],b[600],ans;
string c;
void dfs(int x,int s,int ss)
{	
	if(s==m)
	{
	  int zs=ss;
	  for(int i=2;i<=n-x+1;i++)
	    zs=(zs*i)%mod;
	  ans=(ans+zs)%mod;
	  return;
	}
	int lj=0;
	for(int i=x-s;i<=500;i++)
	  lj+=t[i];
	if(lj+s<m||b[n]-b[x-1]<m-s||x>n)
	  return;
	for(int i=0;i<=500;i++)
	  if(t[i]>0)
	  {
	  	t[i]--;
	  	if(i>=x-s&&b[x]-b[x-1]>0)
	  	  dfs(x+1,s+1,ss*(t[i]+1)%mod);
	  	else
	  	  dfs(x+1,s,ss*(t[i]+1)%mod);
	  	t[i]++;
	  }
}
signed main()
{
	int x;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>c;
	for(int i=1;i<=n;i++)
	{
	  cin>>x;
	  t[x]++;
	  b[i]=c[i-1]-'0'+b[i-1];
	}
	dfs(1,0,1);
	cout<<ans;
	return 0;
}

