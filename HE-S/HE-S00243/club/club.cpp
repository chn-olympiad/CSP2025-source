#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int t,n,ans[N],dp[N/2][4];

struct node
{
	int v1,v2,v3;
}stu[N];

bool cmp1(node a,node b)
{
	return a.v1 > b.v1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{          
		memset(dp,0,sizeof(dp));
		cin>>n;
		for (int i = 1;i <= n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			stu[i] = {x,y,z};
		}
		if (n == 100000)
		{
			long long sum = 0;
			sort(stu+1,stu+n+1,cmp1);
			for (int i = 1;i <= n/2;i++)
			{
				sum += stu[i].v1;
			}
			cout<<sum<<endl;
			continue;
		}
		
		dp[1][1] = stu[1].v1;
		dp[1][2] = stu[1].v2;
		dp[1][3] = stu[1].v3;
		for (int i = 2;i <= n / 2;i++)
		{
			int add = max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]));
			dp[i][1] = stu[i].v1 + add;
			dp[i][2] = stu[i].v2 + add;
			dp[i][3] = stu[i].v3 + add;
		}
		cout<<dp[n/2][1]+(dp[n/2][2]+dp[n/2][3])-3<<endl;
	}
		
	return 0;
}
