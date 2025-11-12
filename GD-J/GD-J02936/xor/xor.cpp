#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 10;
ll n, k, a[N], ans, res, tmp, cnt1, cnt0;
bool flagA = 1, flagB = 1, flagC = 1;

int main() {
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] == 1) cnt1++;
		else if(a[i] == 0) cnt0++;
		
		if(a[i] != 1) flagA = 0;
		if(a[i] != 1 && a[i] != 0) flagB = 0;
	}
	
	if(k == 0 && flagA) {
		cout << n / 2;
	}
	
	else if(flagB) {
		if(k == 1) {
			cout << cnt1;
		}
		else if(k == 0) cout << cnt0;
	}
	
	
	
	return 0;
} 
