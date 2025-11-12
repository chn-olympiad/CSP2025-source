#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	int T2 = T;
	
	long long sum[T] = {};
	
	while(T--) {
		int n;
		cin >> n;
		int a1[n], a2[n], a3[n];
		for(int i = 0; i < n; ++i) 
			cin >> a1[i] >> a2[i] >> a3[i];
		bool f = 1;
		for(int i = 0; i < n; ++i) 
			if(a2[i] != 0 && a3[i] != 0) f = 0;
		if(f) {
			for(int i = 0; i < n; ++i) {
				sum[T] += a1[i];
			}
		}
		for(int i = 0; i < n; ++i) 
			sum[T] += max(max(a1[i], a2[i]), a3[i]);
	}
	
	for(int i = T2 - 1; i >= 0; --i) cout << sum[i] << endl;
}