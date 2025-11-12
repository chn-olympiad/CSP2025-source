#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
int s[100005][5];
int ans=0;
void dfs(int i,int a,int b,int c,int sum)
{
	if(a>n/2||b>n/2||c>n/2)
	{
		return ;
	}
	if(i==n+1)
	{
		ans=max(ans,sum);
		return ;
	}
	dfs(i+1,a+1,b,c,sum+s[i][1]);
	dfs(i+1,a,b+1,c,sum+s[i][2]);
	dfs(i+1,a,b,c+1,sum+s[i][3]);
	return ;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i][1]>>s[i][2]>>s[i][3];
		}
		if(n<=20) 
		{
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
