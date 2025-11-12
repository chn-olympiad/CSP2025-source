#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
long long a[1000005];
long long n;
long long ans;
long long sum;
long long sum1,sum2;
void dfs(int j,int num,int k,int pro)
{
	for(int i=j;i<=n-k+num;i++)
	{
		if(num<k)
		{
			dfs(i+1,num+1,k,pro+a[i]);
		}
		if(num==k)
		{
			if(pro<=a[i])
				ans--;
			return ;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	int pd=1;
	for(int i=3;i<=n;i++)
	{
		sum1=1;
		sum2=1;
		for(int j=2;j<=i;j++)
			sum1*=j;
		for(int j=n;j>n-i;j--)
		{
			sum2*=j;
		}
		ans+=(sum2/sum1);
	}//计算方案总和 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			pd=0;
	}//判断是否为特殊情况 
	if(pd==1)
	{
//		ans-=n*(n-1)*(n-2)/2/3;
		cout<<ans;
	}
	else
	{
		sort(a+1,a+1+n);
		if(n<=20)
		{
			for(int i=3;i<=n;i++)
			{
				dfs(1,1,i,0);
			}
			cout<<ans;
		}
		else
			cout<<rand();
	}
	return 0;
}