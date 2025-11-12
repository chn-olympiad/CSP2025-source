#include<bits/stdc++.h>
using namespace std;
struct member {
	int id, a, b, c;
};
bool cmpa(member m1, member m2) {
	return m1.a > m2.a;
}
bool cmpb(member m1, member m2) {
	return m1.b > m2.b;
}
bool cmpc(member m1, member m2) {
	return m1.c > m2.c;
}
int t;
int main() {
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	cin >> t;
	for(int i = 0; i < t; i++) {
		int n, maxn, ans = 0, la = 0, lb = 0, lc = 0;
		//int a = 0, b = 0, c = 0;
		cin >> n;
		maxn = n / 2;
		member a[50005];
		for(int j = 1; j <= n; j++)	{
			cin >> a[j].a >> a[j].b >> a[j].c;
			a[j].id = j;
		}
//		cout << a[1].a << " " << a[1].b << " " << a[1].c;
		int u[n + 1], mans1 = 0, mans2 = 0, mans3 = 0;
		memset(u + 1, sizeof(u), 0);
		sort(a + 1, a + n + 1, cmpa);
		for(int k = 1; k <= 2; k++) {
			if(u[k] != 1) {
				mans1 += a[k].a;
				u[k] = 1;
			}
		}
		sort(a + 1, a + n + 1, cmpb);
		for(int k = 1; k <= 2; k++) {
			if(u[k] != 1) {
				mans1 += a[k].b;
				u[k] = 1;
			}
		}
		sort(a + 1, a + n + 1, cmpc);
		for(int k = 1; k <= 2; k++) {
			if(u[k] != 1) {
				mans1 += a[k].c;
				u[k] = 1;
			}
		}	
	//
		memset(u + 1, sizeof(u), 0);
		sort(a + 1, a + n + 1, cmpa);
		for(int k = 1; k <= 2; k++) {
			if(u[k] != 1) {
				mans2 += a[k].a;
				u[k] = 1;
			}
		}
		sort(a + 1, a + n + 1, cmpc);
		for(int k = 1; k <= 2; k++) {
			if(u[k] != 1) {
				mans2 += a[k].c;
				u[k] = 1;
			}
		}
		sort(a + 1, a + n + 1, cmpb);
		for(int k = 1; k <= 2; k++) {
			if(u[k] != 1) {
				mans2 += a[k].b;
				u[k] = 1;
			}
		}
		//
		memset(u + 1, sizeof(u), 0);
		sort(a + 1, a + n + 1, cmpc);
		for(int k = 1; k <= 2; k++) {
			if(u[k] != 1) {
				mans3 += a[k].c;
				u[k] = 1;
			}
		}
		sort(a + 1, a + n + 1, cmpb);
		for(int k = 1; k <= 2; k++) {
			if(u[k] != 1) {
				mans3 += a[k].b;
				u[k] = 1;
			}
		}
		sort(a + 1, a + n + 1, cmpa);
		for(int k = 1; k <= 2; k++) {
			if(u[k] != 1) {
				mans3 += a[k].a;
				u[k] = 1;
			}
		}
		
		//ans = max(mans1, max(mans2, mans3));
		cout << mans1 << " " << mans2 << " " << mans3;
	}
	return 0;
}
