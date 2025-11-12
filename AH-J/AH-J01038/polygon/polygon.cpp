#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int b[5005];
int Maxyou[5005];
int ans=0;
bool bb=true;
void f(int n)
{
	int ans=1;
	for(int i=1;i<=n;i++)
	ans=ans*2%998244353;
	ans=ans-1-n-n*(n-1)/2;
	if(ans<0)
	ans+=998244353;
	cout<<ans;
}
void dfs(int now,int sum,int Max,int x)
{
	if(now==n+1)
	{
		if(sum>Max*2&&x>=3)
		ans++;
		ans=ans%998244353;
		return ;
	}
	if(n-now+1+x<3)
	return ;
	if(sum+b[n]-b[now-1]<=Max*2)
	return ;
	if(sum>max(Maxyou[now],Max)*2)
	{
		int s=1;
		for(int i=now;i<=n;i++)
		s=s*2%998244353;
		ans=(ans+s)%998244353;
		return ;
	}
	dfs(now+1,sum,Max,x);
	dfs(now+1,sum+a[now],max(Max,a[now]),x+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
		if(a[i]!=1)
		bb=false;
	}	
	for(int i=n;i>=1;i--)
	for(int j=i;j<=n;j++)
	Maxyou[i]=max(Maxyou[i],a[j]);
	if(n<=2)
	{
		cout<<0;
		return 0;
	}
	if(bb==true)
	{
		f(n);
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans%998244353;
	return 0;
}
