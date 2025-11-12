#include <bits/stdc++.h>
using namespace std;
int scores[10 * 10 + 100];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m; // n行m列 
	cin >> n >> m;
	int maxnm = n * m;
	for (int i = 1; i <= maxnm; i++) {
		cin >> scores[i];
	}
	
	int rsc = scores[1];
	int c = 1, r = 0; // c列r行 
	bool rev = 0; // 蛇形往回走 
	sort(scores + 1, scores + maxnm + 1, cmp);
	for (int i = 1; i <= maxnm; i++) {
		if (!rev) {
			// 正向走
			// 行数增加
			r++;
			// 超过行数
			if (r > n) {
				// 列数增加 r到n 下一轮反着走 
				c++;
				rev = 1;
				r = n;
			} 
		} else {
			// 反着走
			// 行数减少 
			r--;
			// r 小于1
			if (r < 1) {
				// 列数加  r到1 下一轮正着
				c++;
				rev = 0;
				r = 1; 
			}
		}
		
		if (scores[i] == rsc) {
			cout << c << " " << r;
			break;
		}
	}
	return 0;
	
}
