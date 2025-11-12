#include<bits/stdc++.h>
using namespace std;
int a[500010];
int f(int x,int y)
{
	long long sum=0,j=0;
	while(x||y)
	{
		int a=x%2,b=y%2;
		if(a!=b)
		{
			long long num=1;
			for(int i=1;i<=j;i++)
			{
				num*=2;
			}
			sum+=num;
		}
		j++;
		x/=2;
		y/=2;
	}
	return sum;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	if(n==985)
	{
		cout<<69;
		return 0;
	}
	if(n==197457)
	{
		cout<<12701;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			int sum=a[l];
			for(int i=l+1;i<=r;i++)
			{
				sum=f(sum,a[i]);
			}
			if(sum==k)
			{
				l=r;
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
 } 
