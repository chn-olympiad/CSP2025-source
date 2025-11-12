#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005],b[5005],c[5005],ans,d[5005];
const int md=998244353; 
vector<ll> q[5005];
bool cmp(ll a1,ll b1)
{
	if(a1<b1) return true;
	else return false;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	c[1]++;
	q[1].push_back(a[1]);
	for(ll i=2;i<=n;i++)
	{
		for(ll j=0;j<c[i-1];j++)
		{
			c[i]++;
			q[i].push_back(q[i-1][j]);
		}
		for(ll j=0;j<c[i-1];j++)
		{
			c[i]++;
			q[i].push_back(q[i-1][j]+a[i]);
		}
		c[i]++;
		q[i].push_back(a[i]);
	}
	for(ll i=3;i<=n;i++)
	{
		for(ll j=c[i-1];j<c[i]-2;j++)
		{
			if(q[i][j]>a[i]*2)
			{
				ans++;
			}
			ans%=md;
		}
	}
	cout<<ans;
	return 0;
}
