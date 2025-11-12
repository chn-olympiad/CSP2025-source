#include <iostream>
using namespace std;

char c[505];
int h[505];
bool vis[505];
int n,m;
int ans;
void dfs(int now,int day,int sum)
{
	if(now && (sum>=h[now] || c[day]=='0'))
	{
		sum++;
	}
	bool f=false;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			continue;
		}
		f=true;
		vis[i]=true;
		dfs(i,day+1,sum);
		vis[i]=false;
	}
	if(!f)
	{
		ans+=(n-sum)>=m;
		ans%=998244353;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		c[i]=ch;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
