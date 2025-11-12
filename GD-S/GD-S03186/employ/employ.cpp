#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int mod=998244353; 
const int maxn=105; 

int p[maxn]; 
int a[maxn]; 
char s[maxn]; 

int n, m;
int ans=0; 

signed main() {
	
	freopen("employ.in", "r", stdin); 
	freopen("employ.out", "w", stdout); 
	
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> s[i]; 
		p[i] = i; 
	}
	for (int i=1; i<=n; i++) cin >> a[i]; 
	
	do {
		int cnt=0; 
		for (int i=1; i<=n; i++) {
			if (cnt >= a[p[i]] || s[i] == '0') {
				cnt++; 
			}
		}
		if (cnt <= n-m) {
			ans++; 
		}
	} while (next_permutation(p+1, p+1+n)); 
	
	cout << ans%mod << endl; 
	return 0; 
}
 
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
 
