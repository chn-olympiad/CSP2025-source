#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const ll MAXN=1e6+5;
const ll inf=LONG_LONG_MAX;
ll a[MAXN];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>=a[1])ans++;
	}
	cout<<(ans-1)/n+1<<" ";
	ll t=(ans-1)%(2*n)+1;
	if(t>n)
	{
		cout<<2*n-t+1;
	}
	else
	{
		cout<<t;
	}
	return 0;
}
