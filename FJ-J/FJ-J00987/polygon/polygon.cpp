#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
using namespace std;
using ll = long long;
const ll MOD = 998244353;
ll n, a[1000005], dp[10000005];

int main(void){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(ll i=1; i<=n; ++i)
		cin >> a[i];
	// special judges of n<=3
	if(n < 3){
		cout << 0 << endl;
		return 0;
	}else if(n == 3){
		ll maxlen = max({a[1], a[2], a[3]});
		if(a[1] + a[2] + a[3] > 2*maxlen)
			cout << 1 << endl;
		else cout << 0 << endl;
		return 0;
	}
	dp[1] = 0;
	dp[2] = 0;
	if(a[1] + a[2] + a[3] > 2*max({a[1], a[2], a[3]})) 
		dp[3] = 1;
	else dp[3] = 0;
	for(int i=4; i<=n; ++i){
		dp[i] = dp[i-1] + a[i]; 
		// i must guessed it wrong but theres no other ways
		dp[i] = max(dp[i], dp[i-1]);
	}
	cout << dp[n]%MOD << endl;
	return 0;
}

/*
11/01 9:30 T4 (T3 skipped)
11/01 9:36 sub 1~3 completed, back to T3
           almost forgot to remove "//"
11/01 10:11 hello i'm back
11/01 10:15 alright i'm leaving for T3
11/01 11:11 finally here
11/01 11:15 dp?
11/01 11:26 god i dont know how to do it
            i gonna AFO
11/01 11:33 freopen check
            the time maybe wrong
11/01 11:40 god its not end at 11:30
11/01 11:54 blueberry is everywhere on my seat
11/01 11:57 I WILL REMEMBER THIS PROBLEM FOREVER(also T3)
            ok 886 
exp. 10pts

[this is this, and that is that. ]
subscribe Astralyn_S plz ^-^(FJ-J00987)
*/
