#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll k=998244353;
ll a[3009],n,ans;
void f(ll x,ll ma,ll sum)
{
	ll i,maxn,su;
	for(i=x+1;i<n;i++)
	{
		maxn=ma,su=sum;
		maxn=max(a[i],maxn);
		su+=a[i];
		if(maxn*2<su)
			ans++;
		f(i,maxn,su);
	}
	ans%=k;
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll i,j;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			f(j,a[j],a[i]+a[j]);
	cout<<ans%k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
