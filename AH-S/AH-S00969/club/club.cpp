#include<bits/stdc++.h>
using namespace std;
int a[20020], b[20020], c[20020];
int s[5];
int m(int a, int b, int c) {
	s[1] = a;
    s[2] = b;
	s[3] = c;
    for (int i = 1; i <= 3; i++) {
		for (int j = 2; j <= 3; j++) {
			if (s[i] < s[j]) {
				swap(s[i],s[j]);
			}
		}
	} 
	return s[1];
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t, n;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int l = 0, x = 0;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a[j] >> b[j] >> c[j];
			x = m(a[j], b[j], c[j]);
			l += x;
		}
		cout << l << endl;
 	}
	return 0;
}
