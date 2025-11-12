#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m;
char s[505];
int c[505];
int vis[505];
int b[505];
long long ans=0;
void dfs(int x)
{
	if(x==n+1)
	{
		int cnt=0,q=0;
		for(int i=1;i<=n;i++)
		{
			if(q<c[b[i]] && s[i]=='1')
				cnt++;
			else
				q++;
		}
		if(cnt>=m)
			ans++,ans%=N;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			b[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n<=25)
	{
		dfs(1);
		cout<<ans<<endl;
	}
	else if(m==n)
	{
		ans=1;
		for(int i=n;i>=1;i--)
		{
			ans*=i;
			ans%=N;
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0' || c[i]==0)
			{
				ans=0;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
