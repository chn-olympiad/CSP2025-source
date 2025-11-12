#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5005,R=998244353;
int n;
ll a[N],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	ll pmax=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pmax=max(pmax,a[i]);
	}
	if(pmax==1)
	{
		for(int i=3;i<=n;i++)
		{
			ll cnt=1;
			for(int j=n;j>=n-i+1;j--)
			{
				cnt=cnt*j;
				cnt%=R;
			}
			ll t=1;
			for(int j=1;j<=i;j++)
			{
				t*=j;
				t%=R;
			}
			cnt/=t;
			ans+=cnt;
			ans%=R;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[3]<a[1]+a[2])
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	
	return 0;
}
