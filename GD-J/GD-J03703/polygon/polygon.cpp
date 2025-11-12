#include "bits/stdc++.h"
#define ll long long
using namespace std;
ll n,a[5010],i,dp[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(i=1;i<=n;i++){
		cin >> a[i];
	}
	int max1 = max(a[1],max(a[2],a[3]));
	if(a[1]+a[2]+a[3] >= 2*max1) cout << 1;
	else cout << 0;
	return 0;
}
