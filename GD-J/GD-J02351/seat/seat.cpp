#include <bits/stdc++.h>
using namespace std;
int n = 0, m = 0;
int S[200];
bool tmppp(int a,int b) {
	return a < b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; ++i) {
		cin >> S[i];
	}
	int a111 = S[0];
	for (int j = 0; j < n * m; ++j) {
		for (int i = 0; i < n * m; ++i) {
			if(tmppp(S[i],S[i +1])) {
				int tmp1 = S[i];
				S[i] = S[i + 1];
				S[i + 1] = tmp1;
			}
		}
	}
	int c = 1,r = 1;
	bool sxzw = 1;
	for (int i = 0; i < n * m; ++i) {
		if(i != 0 && sxzw)r++;
		else if (!sxzw) r--;
	
		if (r > n && sxzw) {
			sxzw = 0;
			r = n;
			c += 1;
		} else if(r < 1 && !sxzw) {
			sxzw = 1;
			r = 1;
			c += 1;
		}
		if (S[i] == a111) {
			break;
		}
	}
	cout << c << ' ' << r;
	return 0;
}
