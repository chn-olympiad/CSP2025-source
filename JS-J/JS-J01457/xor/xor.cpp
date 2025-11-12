#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e3+5;
ll a[MAXN],dp[MAXN][MAXN],k,n;
vector< pair<ll,ll> >vec;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	for(ll i = 1;i <= n;i++)
	{
		for(ll j = 1;j <= i;j++)
		{
			dp[i][j]=a[i];
			for(ll k = i+1;k <= j;k++)
			{
				dp[i][j]^=a[k];
			}
		}
	}
	
	for(ll i = 1;i <= n;i++)
	{
		for(ll j = 1;j <= i;j++)
		{
			if(dp[i][j]==k)
			{
				vec.push_back({i,j});
			}
		}
	}
	cout<<vec.size();
	return 0;
}