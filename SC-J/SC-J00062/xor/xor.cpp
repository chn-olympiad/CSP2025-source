#include <bits/stdc++.h>

using namespace std; 

int n, k, cnt, maxn, cur; 
int A[500005];

int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout); 

	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		cur = 0;
		for (int j = i; j > maxn; j--) {
			cur ^= A[j];
			if (cur == k) {
				cnt++;
				maxn = i;
				break;
			}
		}
	}
	
	cout << cnt;
	
	return 0;
}