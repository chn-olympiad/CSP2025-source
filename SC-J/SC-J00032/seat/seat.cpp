#include <bits/stdc++.h>
#define int long long
using namespace std;

const int limit = 1e2 + 10;
int height, width, tgt;
int score[limit], matrix[limit][limit];

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> height >> width;
	
	for (int pos = 1; pos <= height * width; pos++) cin >> score[pos];
	
	tgt = score[1];
	
	sort(score + 1, score + height * width + 1, greater<int>());
	
	int cur = 1;
	
	for (int ord = 1; ord <= width; ord++) 
		if (ord & 1) {
			for (int absc = 1; absc <= height; absc++) { 
				matrix[absc][ord] = score[cur++];
				if (matrix[absc][ord] == tgt) return cout << ord << ' ' << absc << '\n', 0;
			}
		} else {
			for (int absc = height; absc >= 1; absc--) {
				matrix[absc][ord] = score[cur++];
				if (matrix[absc][ord] == tgt) return cout << ord << ' ' << absc << '\n', 0;
			}
		}
	
	return 0;
}