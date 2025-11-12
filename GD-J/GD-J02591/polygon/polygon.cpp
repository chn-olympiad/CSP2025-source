#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=5e3+6;
typedef long long ll;
const ll INF=998244353;
ll n,a[N],dp[N];
ll ans=0;
void f(ll pos,ll top,ll m,ll sum)
{
	if(pos>top)
	{
		if(sum>2*a[m])
			ans=(ans+1)%INF;
		return;
	}
	for(int i=m+1;i<=n-top+pos;i++)
	{
		f(pos+1,top,i,sum+a[i]);
	}
	return;
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
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		f(1,i,0,0);
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
