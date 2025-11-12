#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=998244353;
ll n,a[5005],sum;
void teshu()
{
	ll tp;
	for(ll i=3;i<=n;i++)
	{
		tp=1;
		for(ll j=n;j>n-i;j--)
		{
			tp=tp*j;
		}
		for(ll j=i;j>=2;j--)
		{
			tp=tp/j;
		}
		tp%=N;
		sum=(sum+tp)%N;
	}
	cout<<sum;
}
ll pd(ll res,ll side,ll dq)
{
	ll ans=0;
	if(side==1)
	{
		while(res>a[dq]&&dq<=n)
		{
			ans++;
			dq++;
		}
		return ans;
	}
	for(ll i=dq;i<=n-side+1;i++)
	{
		ans+=pd(res+a[i],side-1l,i+1l);
		ans%=N;
	}
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=1;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			f=0;
	}
	if(f)
	{
		teshu();
		return 0;	
	}
	sort(a+1,a+1+n);
	for(ll i=3;i<=n;i++)
	{
		sum=(sum+pd(0l,i,1l))%N;
	}
	cout<<sum;
	return 0;
}
