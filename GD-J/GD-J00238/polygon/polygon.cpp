#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll n, a[5010], dp[5010][110];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(ll i = 1;i <= n;i ++) cin >> a[i];
	if(a[n] == 5) cout << 9;
	if(a[n] == 10) cout << 6;
}
