#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[5005],f[5005];
void dfs(long long step,long long sum,long long maxn,long long p)
{
	if(step==n+1) 
	{
		if(sum>maxn*2) 
		{
			ans++;
			ans%=99824453;
		}
		return ;
	}
	if(step>=3&&sum>maxn*2) 
	{
		ans++;
		ans%=99824453;
	}
	for(int i=p+1;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			dfs(step+1,sum+a[i],max(maxn,a[i]),i);
			f[i]=0;
		}
	}
}
long long C(long long m,long long n)
{
	long long shang=1,xia=1;
	if(m*2>n) m=n-m;
	for(int i=n;i>=n-m+1;i--) 
	{
		shang=shang*i%998244353;
	}
	for(int i=n-m+1;i>=1;i--) 
	{
		xia=xia*i%998244353;
	}
	return shang/xia%998244353;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=50)
	{
		dfs(1,0,INT_MIN,0);
		cout<<ans;
	}
	else
	{
		for(int i=3;i<=n;i++)
		{
			ans+=C(i,n);
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}
