#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],vis[505];
long long ans=0;
string s;
void dfs(int x,int num)
{
	//cout<<x<<' '<<num<<endl;
	if(x==n+1)
	{
		if(num<=n-m)
			ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		//cout<<c[i]<<' ';
		if(vis[i])continue;
		vis[i]=1;
		if(s[x-1]=='0' or num>=c[i])dfs(x+1,num+1);
		else dfs(x+1,num);
		vis[i]=0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool flag=1;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')flag=0;
	}
	if(flag)
	{
		sort(c+1,c+n+1);
		int cnt0=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]!=0)break;
			cnt0++;
		}
		if(cnt0>=n-m)
		{
			cout<<0;
			return 0;
		}
		if(cnt0==0){
			long long ans=1;
			for(int i=2;i<=n;i++)ans=(ans*i)%mod;
			cout<<ans;
			return 0;
		}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
