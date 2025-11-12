#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n * m);
	for(int i = 0; i < n * m; ++i) {
		cin >> a[i];
	}
	int R = a[0];
	sort(a.rbegin(), a.rend());
	for(int i = 0, c = 1, r = 0, flag = 0; i < n * m; ++i) {
		if(!flag) {
			if(r < n) {
				++r;
			} else {
				++c;
				flag = 1;
			}
		} else {
			if(r > 1) {
				--r;
			} else {
				++c;
				flag = 0;
			}
		}
		if(a[i] == R) {
			cout << c << " " << r;
			return 0;
		}
	}
}
