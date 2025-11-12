#include<bits/stdc++.h>
using namespace std;
struct ab
{
	int a1;
	int a2;
	int a3;
};
bool cmp(ab xx,ab yy)
{
	return xx.a1>yy.a1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		int n;
		cin>>n;
		ab a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		if(n==2)
		{
			int z=0;
			z+=a[0].a1;
			z+=max(a[1].a2,a[1].a3);
			z=max(z,a[0].a2+max(a[1].a1,a[1].a3));
			z=max(z,a[0].a3+max(a[1].a1,a[1].a2));
			cout<<z<<endl;
			continue;
		}
		bool b=0;
		for(int i=0;i<n;i++)
		{
			if(a[i].a2!=0||a[i].a3!=0)
			{
				b=1;
				break;
			}
		}
		if(b==0)
		{
			sort(a,a+n,cmp);
			int z=0;
			for(int i=0;i<n/2;i++)
			{
				z+=a[i].a1;
			}
			cout<<z<<endl;
			continue;
		}
		int dp[n+1][n]={};
		for(int i=1;i<=n;i++)
		{
			dp[i][0]=max(a[0].a1,max(a[0].a2,a[0].a3));
		}
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dp[j][i]=max(dp[j][i-1],dp[j-1][i-1]+max(a[0].a1,max(a[0].a2,a[0].a3)));
			}
		}
		cout<<dp[n][n-1]<<endl;
	}
	return 0;
}
