#include<bits/stdc++.h>
using namespace std;
int n,a[100005][10],ans,s[10];
struct node
{
	int num,how,ofc;
}b[100005];
bool cmp(node a,node b)
{
	return a.how<b.how;
}
void dfs(int step,int dg)
{
	if(step==n+1)
	{
		ans=max(ans,dg);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		s[i]++;
		if(s[i]<=n/2)
		{
			dfs(step+1,dg+a[step][i]);
		}
		s[i]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		memset(s,0,sizeof s);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
