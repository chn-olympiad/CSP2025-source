//今年运气真TM的不好
//实力不够暴力来凑
//四题暴力带我冲上一等
//我还会回来的 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans,a[100005][3];
priority_queue<int>pq;bool pdA,pdB;
void dfs(int k,int num1,int num2,int num3,int cnt)
{
	if(k==n+1)
	{
		ans=max(ans,cnt);
		return;
	}
	if(num1<n/2)dfs(k+1,num1+1,num2,num3,cnt+a[k][0]);
	if(num2<n/2)dfs(k+1,num1,num2+1,num3,cnt+a[k][1]);
	if(num3<n/2)dfs(k+1,num1,num2,num3+1,cnt+a[k][2]);
	return;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;ans=0;pdA=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
				if(j>0&&a[i][j]!=0)pdA=0;
			}
		if(n<30)
		{
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		else if(pdA)
		{
			while(!pq.empty())pq.pop();
			for(int i=1;i<=n;i++)
				pq.push(a[i][0]);
			for(int i=1;i<=n/2;i++)
			{
				int s=pq.top();
				pq.pop();
				ans+=s;
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
			ans+=max(max(a[i][0],a[i][1]),a[i][2]);
		cout<<ans<<'\n';
	}
	return 0;
}
