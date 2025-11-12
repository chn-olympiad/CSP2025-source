#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int read()
{
	char ch;
	int s=0;
	ch=getchar();
	while (ch<'0'||ch>'9')
	{
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		
		s=s*10+(ch-'0');
		ch=getchar();
	}
	return s;
}
int n,a[5005],he[5005];
long long ans;
bool vis[5005];
long long dfs(int st,int s,int p)
{
	long long cnt=0;
	if (s>p&&s-a[st]<p&&st<p)
	cnt=1;
	for (int i=st+1;i<p;i++)
	{
		if (!vis[i])
		{
			vis[i]=true;
			cnt+=dfs(i,s+a[i],p);
			vis[i]=false;
		}
	}
	return cnt;
}
struct node
{
	int js,len;
}dp[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+1+n);
	/*for (int i=1;i<=cnt;i++)
	cout<<a[i];
	cout<<endl;*/
	for (int i=1;i<=n;i++)
	{
		he[i]=a[i]+he[i-1];
		if (i<3) continue;
		for (int j=1;j<=i-2;j++)
		ans=(ans+dfs(j,a[j],i))%mod;
		memset(vis,0,sizeof(vis));
	    ans=ans%mod;
	}
	cout<<ans%mod;
	return 0;
}
