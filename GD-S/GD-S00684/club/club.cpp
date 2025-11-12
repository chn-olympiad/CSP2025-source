#include<bits/stdc++.h>
using namespace std;

struct Manyi {
	int a1, a2, a3;
};

int cmp(Manyi a, Manyi b) {
	if (a.a1 == 0 || a.a2 == 0 || a.a3 == 0) {
		return -1;
	}
	if (b.a1 == 0 || b.a2 == 0 || b.a3 == 0) {
		return 1;
	}
	return (a.a1 + a.a2 + a.a3) > (b.a1 + b.a2 + b.a3);
}

bool debug = false;

int main()  {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		Manyi ms[n];
		for (int j = 0; j < n; j++) {
			int a1, a2, a3;
			cin >> a1 >> a2 >> a3;
			ms[j] = {a1, a2, a3};
		}
		
		int limit = n / 2;
		long long manyi = 0;
		int a1 = 0, a2 = 0, a3 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (cmp(ms[i], ms[j])) {
					swap(ms[i], ms[j]);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			Manyi m = ms[i];
			int x = max(m.a1, max(m.a2, m.a3));
			int z = min(m.a1, min(m.a2, m.a3));
			int y = m.a1 + m.a2 + m.a3 - x - z;
			if (debug) cout << "x: " << x << " y: " << y << " z: " << z << endl;
			if (x == m.a1) {
				if (a1 < limit) {
					// a1
					a1 += 1; manyi += m.a1;
					if (debug) cout << i << " -> a1" << endl;
				} else {
					// a1无位 
					if (y == m.a2) {
						if (a2 < limit) {
							// a2
							a2 += 1; manyi += m.a2;
							if (debug) cout << i << " -> a2" << endl;
						} else {
							// a2无位 
							// a3
							a3 += 1; manyi += m.a3;
							if (debug) cout << i << " -> a3" << endl;
						}
					} else {
						// a3
						a3 += 1; manyi += m.a3;
						if (debug) cout << i << " -> a3" << endl;
					}
				}
			} else if (x == m.a2) {
				if (a2 < limit) {
					// a2
					a2 += 1; manyi += m.a2;
					if (debug) cout << i << " -> a2" << endl;
				} else {
					// a2无位 
					if (y == m.a1) {
						if (a1 < limit) {
							// a1
							a1 += 1; manyi += m.a1;
							if (debug) cout << i << " -> a1" << endl;
						} else {
							// a1无位 
							// a3
							a3 += 1; manyi += m.a3;
							if (debug) cout << i << " -> a3" << endl;
						}
					} else {
						// a3
						a3 += 1; manyi += m.a3;
						if (debug) cout << i << " -> a3" << endl;
					}
				}
			} else if (x == m.a3) {
				if (debug && x == 9953) cout << "bbb";
				if (a3 < limit) {
					// a3
					a3 += 1; manyi += m.a3;
					if (debug) cout << i << " -> a3" << endl;
				} else {
					if (debug && x == 9953) cout << "ccc";
					// a3无位 
					if (y == m.a1) {
						if (debug && x == 9953) cout << "ddd";
						if (a1 < limit) {
							// a1
							a1 += 1; manyi += m.a1;
							if (debug) cout << i << " -> a1" << endl;
						} else {
							// a1无位 
							// a2
							a2 += 1; manyi += m.a2;
							if (debug) cout << i << " -> a2" << endl;
						}
					} else {
						if (debug && x == 9953) cout << "eee";
						// a2
						a2 += 1; manyi += m.a2;
						if (debug) cout << i << " -> a2" << endl;
					}
				}
			}
		}
		
		cout << manyi << endl;
	}
	
	return 0;
}
