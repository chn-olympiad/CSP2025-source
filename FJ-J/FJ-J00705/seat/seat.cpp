#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m, s;
int w[N];
int r_score, r_f;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	s = n * m;
	for(int i = 1; i <= s; i ++) {
		int score; 
		cin >> score;
		if(i == 1) {
			r_score = score;
		}
		w[i] = score;
	}
	sort(w + 1, w + s + 1, cmp);
	for(int i = 1; i <= s; i ++) {
		if(w[i] == r_score)
			r_f = i;
	}
	//特殊性质很无奈，精打细算把人害
	if(r_f <= n)
		cout << 1 << " " << r_f; 
	else if(r_f % n == 0) {
		int idx = r_f / n;
		if(idx % 2 == 0)
			cout << idx << " " << 1;
		else
			cout << idx << " " << n;
	}
	else {
		int y = ceil(1.0 * r_f / n), x;
		if(y % 2 == 0) {
			x = y * n - r_f + 1;
		}
		else {
			x = r_f % n;
		}
		cout << y << " " << x;
	}
	return 0;
}
