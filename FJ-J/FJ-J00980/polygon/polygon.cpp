#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int dp[1005][1005];
int n;
int sum;
int a[N];
int cmp(int a,int b)
{
	return a>b;
}
int ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	if(n<3)
	{
		printf("0\n");
		return 0;
	}
	else if(n<=3)
	{
		sort(a+1,a+n+1,cmp);
		if(a[n]+a[n-1]<=a[1])
		{
			printf("0\n");
			return 0;
		}
		else
		{
			printf("1\n");
		}
	}
	for(int len=3;len<=n;len++)
	{
		for(int i=1;i<=n;i++)
		{
			int j=len+i-1;
			for(int l=i;l<j;l++)
			{
				sum+=a[l];
			}
			for(int k=i;k<j;k++)
			{
				int maxn=a[i];
				if(sum>maxn)
				{
					ans++;
				}
			}
		}
	}
	printf("%d",ans);
}
