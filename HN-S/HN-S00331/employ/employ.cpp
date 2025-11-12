#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[501],b[501],maxn;
char c[501];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>c[i];
	for(ll i=1;i<=n;i++)cin>>a[i];
	do
	{
		ll cnt=0;
		for(ll i=1;i<=n;i++)
		{
			//cout<<a[i]<<" ";
			b[i]=a[i];
		}
		//cout<<endl;
		for(ll i=1;i<=n;i++)
		{
			if(c[i]=='1'&&b[i]>0)cnt++;
			else
			{
				for(ll j=i;j<=n;j++)b[j]--;
			}
		}
		//cout<<cnt<<endl;
		if(cnt>=m)maxn=(maxn+1)%998244353;
	}while(next_permutation(a+1,a+1+n));
	do
	{
		ll cnt=0;
		for(ll i=1;i<=n;i++)
		{
			//cout<<a[i]<<" ";
			b[i]=a[i];
		}
		//cout<<endl;
		for(ll i=1;i<=n;i++)
		{
			if(c[i]=='1'&&b[i]>0)cnt++;
			else
			{
				for(ll j=i;j<=n;j++)b[j]--;
			}
		}
		//cout<<cnt<<endl;
		if(cnt>=m)maxn=(maxn+1)%998244353;
	}while(next_permutation(a+1,a+1+n));
	cout<<maxn;
	return 0;
}
