#include<bits/stdc++.h>
using namespace std;
int v[100005][5],vv[100005],cnt[100005][5];
long long dp[100005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(cnt,0,sizeof(cnt));
		memset(dp,0,sizeof(dp));
		int n,nn,ans=-1;
		bool b=1;
		cin>>n;
		nn=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>v[i][1]>>v[i][2]>>v[i][3];
			if(v[i][2]!=0||v[i][3]!=0)
				b=0;
		}
		if(b==1)
		{
			for(int i=1;i<=n;i++)
				vv[i]=v[i][1];
			sort(vv+1,vv+1+n,cmp);
			int sum=0;
			for(int i=1;i<=nn;i++)
				sum+=vv[i];
			cout<<sum<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=n;j>=1;j--)
			{
				for(int k=1;k<=3;k++)
				{
					if(dp[j]<dp[j-1]+v[i][k]&&cnt[j][k]<=nn)
					{
						dp[j]=dp[j-1]+v[i][k];
						cnt[j][k]++;
					}				
				}
			}
		}
		for(int i=0;i<=n;i++)
			if(ans<dp[i])
				ans=dp[i];
		cout<<ans<<endl;
	}
	return 0;
}
