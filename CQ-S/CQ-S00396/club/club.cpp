#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int t,n;
int a[N][3],dp[N];

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		bool flag1=0,flag2=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][1]) flag1=1;
			if(a[i][2]) flag2=1;
		}
		if(!flag1)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=n/2;j>=1;j--)
				{
					dp[j]=max(dp[j],dp[j-1]+a[i][0]);
				}
			}
			cout<<dp[n/2]<<endl;
			continue;
		}
		if(!flag2)
		{
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				sum+=a[i][0]+a[i][1];
				for(int j=n/2;j>=1;j--)
				{
					dp[j]=max(dp[j],dp[j-1]+a[i][0]);
				}
			}
		}
		if(n==2)
		{
			int max1=0,maxx1=0;
			for(int i=0;i<=2;i++)
			{
				if(a[1][i]>max1)
				{
					maxx1=i; max1=a[1][i];
				}
			}
			int max2=0,maxx2=0;
			for(int i=0;i<=2;i++)
			{
				if(a[2][i]>max2)
				{
					maxx2=i; max2=a[2][i];
				}
			}
			if(maxx1!=maxx2)
			{
				cout<<max1+max2<<endl;
				continue;
			}
			int max1x=0,maxxx1=0;
			for(int i=0;i<=2;i++)
			{
				if(a[1][i]>max1x && i!=maxx1)
				{
					maxxx1=i;
					max1x=a[1][i];
				}
			}
			int max2x=0,maxxx2=0;
			for(int i=0;i<=2;i++)
			{
				if(a[2][i]>max2x && i!=maxx2)
				{
					maxxx2=i;
					max2x=a[2][i];
				}
			}
			cout<<max(max1+max2x,max2+max1x)<<endl;
			continue;
		}
	}
}

