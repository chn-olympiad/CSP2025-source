#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],ans,b[505];
char c[505];
void dfs(int setp,int cnt)
{
	if(setp>n)
	{
		if(cnt>=m)
		{
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=setp;
			if(c[setp]=='1'&&setp-1-cnt<a[i])
			{
				dfs(setp+1,cnt+1);
			}
			else
			{
				dfs(setp+1,cnt);
			}
			b[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
} 
