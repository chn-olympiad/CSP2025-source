#include<iostream>
using namespace std;
const int mod=998244353;
int n,m,c[505],f[505],vis[505],ans;
string s;
void dfs(int x)
{
	if(x>n)
	{
		int sum=0;
		for (int i=1;i<=n;i++)
			if(s[i-1]=='1'&&i-1-sum<c[f[i]])
				sum++;
		if(sum>=m)
			ans++;
		return ;
	}
	for (int i=1;i<=n;i++)
		if(vis[i]==0)
		{
			vis[i]=1;
			f[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for (int i=1;i<=n;i++)
		scanf ("%d",&c[i]);
	if(n<=10)
	{
		dfs(1);
		printf ("%d",ans);
	}
	else if(m==n)
	{
		for (int i=0;i<s.length();i++)
			if(s[i]=='0')
				ans=-1;
		for (int i=1;i<=n;i++)
			if(c[i]==0)
				ans=-1;
		if(ans==-1)
			printf ("0");
		else
		{
			for (int i=1;i<=n;i++)
				ans=(1ll*ans*i)%mod;
			printf ("%d",ans);
		}
	}
	return 0;
}
