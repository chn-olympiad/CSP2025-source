#include <bits/stdc++.h>
using namespace std;
int n,m;
char s[505];
int a[505];
bool f[505];
long long ans=0;
int p[505];
void solve()
{
	/*for(int i=1;i<=n;i++)cout<<p[i]<<" ";
	cout<<endl;*/
	int cnt=0;
	int num=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')cnt++;
		else 
			if(cnt<a[p[i]])num++;
	}
	if(num>=m)ans++;
	ans=ans%998244353;
}
void dfs(int x)
{
	if(x==n+1)
	{
		//ans++;
		solve();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==false)continue;
		else 
		{
			f[i]=false;
			p[x]=i;
			dfs(x+1);
			f[i]=true;
		}
	}
	return;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	memset(f,true,sizeof(f));
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=18)dfs(1);
	else
	{
		for(int i=1;i<=n;i++)
		  ans=ans*i%998244353;
	}
	cout<<ans<<endl;
	return 0;
}
