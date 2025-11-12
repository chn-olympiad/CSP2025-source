#include<bits/stdc++.h>
using namespace std;
int n,a[11111],ans;
const int mod=998244353;
int f(int x)
{
	if(x>n-x)
	x=n-x;
	int p1=1,p2=1;
	for(int i=n;i>=n-x+1;i--)
	p1=p1*i%mod;
	for(int i=x;i>=1;i--)
	p2=p2*i%mod;
	return p1/p2;
}
void dfs(int k,int l,int sum)
{
	if(k>n)
	return;
	if((sum+a[k])>(2*a[k]) && (l+1)>=3)
	{
		ans++;
		ans%=mod;
	}
	dfs(k+1,l,sum);
	dfs(k+1,l+1,sum+a[k]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]==a[n])
	{
		for(int i=3;i<=n;i++)
		{
			ans+=f(i)%mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
