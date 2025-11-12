#include<bits/stdc++.h>
using namespace std;
int s[50005],a[50005];
long long ans;int n;
void dfs(int step,int k,int sum,int w,int maxn)
{
	if(w==k)
	{
		if(sum>maxn*2)
		ans++;
		ans%=998244353;
		return;
	}
	for(int i=step-1;i>=k-w;i--)
	{
		if(maxn!=-1)
		dfs(i,k,sum+a[i],w+1,maxn);
		else
		dfs(i,k,sum+a[i],w+1,a[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[a[i]]++;
	} 
	sort(a+1,a+1+n);
	if(n==3)
	{
		if(a[3]>a[1]+a[2])
		{
			cout<<'0';	
		}
		else
		cout<<'1';
		return 0;
	}
	else if(n<=100)
	{
		for(int i=3;i<=n;i++)
		dfs(n+1,i,0,0,-1);
		cout<<ans;
		return 0;
	}
	else{
		long long fz=1,fm=1;
		for(int i=3;i<=n;i++)
		{
			for(int j=n;j>=n-i+1;j--)
			fz*=j;
			for(int j=1;j<=i;j++)
			fm*=j;
			ans+=(ans+(fz/fm))%998244353;
		}
		cout<<ans;
	}
	return 0;
}
