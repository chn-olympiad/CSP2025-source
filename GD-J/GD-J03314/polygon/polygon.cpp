#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5005;
const int MOD = 998244353;
int n,a[N],maxn = INT_MIN;

int OwO(int a,int b){
	if (a == b) return 1;
	int x = 1,y = 1;
	for (int i = b;i >= b-a+1;i--) x *= i,x %= MOD;
	for (int i = 1;i <= a;i++) y *= i,y %= MOD;
	return (x / y) % MOD;
}

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i],maxn = max(maxn,a[i]);
	if (maxn == 1){
		int ans = 0;
		for (int i = 3;i <= n;i++)
			ans += OwO(i,n) % MOD;
		cout << ans % MOD << endl;
		return 0;
	}

	return 0;
}
/*
5
1 2 3 4 5

5
2 2 3 8 10

*/
