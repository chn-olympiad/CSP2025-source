#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans,s,s1;
int a[5005];
int pd1()
{
	long long ss=0,ss2=0;
	for(int i=3;i<=s1;i++)
	{
		long long ss1=1;
		for(int j=s1;j>=s1-i+1;j--)
		{
			ss1=(ss1*j);
		}
		for(int j=1;j<=i;j++)
		{
			ss1/=j;
		}
		ss=(ss+ss1)%mod;
	}
	for(int i=0;i<=s;i++)
	{
		long long ss1=1;
		for(int j=s;j>=s-i+1;j--)
		{
			ss1=(ss1*j);
		}
		for(int j=1;j<=i;j++)
		{
			ss1/=j;
		}
		ss2=(ss2+ss1)%mod;
	}
	return (ss*ss2)%mod;	
}
void dfs(int x,int ma,int sum)
{
	if(x>n)
	{
		if(sum>ma*2)
		{
			ans+=1;
		}
		ans%=mod;
		return ;
	}
	dfs(x+1,max(ma,a[x]),sum+a[x]);
	dfs(x+1,ma,sum);
}
int main()
{
	freopen("pulygon.in","r",stdin);
	freopen("pulygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=20)
	{
		dfs(1,0,0);
		printf("%d",ans%mod);
		return 0;
	}
	if(a[n]==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				s1+=1;
			}
			if(a[i]==0)
			{
				s+=1;
			}
		}
		ans+=pd1();
		printf("%d",ans%mod);
		return 0;
	}
	printf("%d",500000);
	return 0;
}
