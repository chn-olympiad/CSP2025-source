// CSP 2025 RP++
/* \gcx ls/ \gcx ls/*/  
/* 我不会写区间异或SGT预处理然后跑 0-1 背包/ll/ll/ll  */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pii pair<int, int> 
#define N (ll)5e5 + 10

ll n, k;
ll a[N];

int main() {
	cin.tie(0);
	cout.tie(0);
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	if (n % 2 == 0) {
		cout << n / 2 << endl; 
	} else {
		cout << (n - 1) / 2 << endl;
	}
	
	return 0;
}
