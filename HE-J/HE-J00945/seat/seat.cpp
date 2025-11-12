#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n, m;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	int seat = n * m; // 记录总人数
	int a[seat + 1];
	
	for (int i = 1; i <= seat; i++)
		cin >> a[i];
	int R_num = a[1]; // 记录小R的成绩 
	
	sort(a + 1, a + seat + 1, cmp); // 按成绩从小到大排序
	
	int ans_lie = 0, ans_hang = 0; // 记录答案 
	for (int i = 1; i <= seat; i++) {
		if (a[i] == R_num) {
			// 计算列 
			if (i % n != 0) ans_lie = i / n + 1;
			else ans_lie = i / n;
			// 计算行 
			if (ans_lie % 2 == 0) ans_hang = n - i % n + 1;
			else {
				ans_hang = i % n;
				if (ans_hang == 0)
					ans_hang = n;
			}
			break; 
		}
	}
	
	cout << ans_lie << " " << ans_hang << endl;
	
	return 0;
}

