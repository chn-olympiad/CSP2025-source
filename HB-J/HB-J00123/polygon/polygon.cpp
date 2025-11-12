#include <bits/stdc++.h>
using namespace std;
int a[5005],n,i,flag=0,last=0;
long long sum=0;
void dfs(int step,int num,int sum1)
{
	if(flag==1)
	{
		return ;
	}
	if(step==i+1)
	{
		if(last*2<sum1)
		{
			sum++;
			sum%=998244353;
		}
		else
		{
			flag=1;
		}
		return ;
	}
	for(int j=num+1;j<=n+step-i;j++)
	{
		last=a[j];
		dfs(step+1,j,a[j]+sum1);
	}
	flag=0;
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(i=3;i<=n;i++)
	{
		dfs(1,0,0);
	}
	cout<<sum;
	return 0;
}
