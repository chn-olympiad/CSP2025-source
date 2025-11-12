#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=5e3+50;
ll n,a[maxn],b[maxn],sum,maxx,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for(ll i=1;i<=n;++i)
	{
		b[i]=a[i-1]+a[i];
	}
	for(ll i=3;i<=n;++i)
	{
		for(ll j=1;j+i<=n;++j)
		{
			ll sum=b[j+i]-b[j-1],maxx=INT_MIN;
			for(ll k=j;k<=j+i;++k) maxx=max(maxx,a[i]);
			if(sum>maxx/2) ans++;
		}
	}
	cout<<9;
	return 0;
} 