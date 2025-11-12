#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s[5005];
long long ans;
long long qpow(int a,int b)
{
	long long res=1;
	while(b)
	{
		if(b&1)
			res*=a,res%=998244353;
		a*=a,a%=998244353;
		b>>=1;
	}
	return res;
}
void dfs(int now,int sum,int mx)
{
	if(now>n)
		return;
	if(sum>mx*2)
	{
		ans+=qpow(2,n-now);
		ans%=998244353;
		return;
	}
	if(sum+s[n]-s[now-1]<=mx*2)
		return;
	dfs(now+1,sum+a[now+1],max(mx,a[now+1]));
	dfs(now+1,sum,mx);
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	dfs(0,0,0);
	cout<<ans;
}
