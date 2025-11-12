#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,ans;

ll a[5001];

void dfs(ll k,ll sum,ll MAX)
{
	k ++;
	sum += a[k];
	if(k >= 3 && MAX * 2 < sum)
	{
		ans ++;
	}
	MAX = max(MAX,a[k]);
	dfs(k + 1,sum,MAX);
}

int main( )
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	
	cin>>n;
	for(ll i = 1;i <= n;i ++)
	{
		cin>>a[i];
	}
	
	dfs(1,0,INT_MIN);
	
	cout<<ans % 998244353;
	
	return 0;
}
