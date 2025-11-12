#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 1e5 + 5;

int t, n, ans;// 新成员数量, 满意度最大值
vector<int, vector<int> > A[4];

struct Node2 {
	int a, b, c;
} a[N];// 满意度

bool cmp(int x, int y) {
	return x > y;
}

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if (ch == '-') {
			f = -f;
		}
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
	}
	return x * f;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "r", stdout);
	// 输入
	t = read();
	while(t--) {
		// 输入
		n = read();
		for(int i = 1; i <= n; i++) {
			a[i].a = read(), a[i].b = read(), a[i].c = read();
			A[1].push_back(a[i].a);
			A[2].push_back(a[i].b);
			A[3].push_back(a[i].c);
		}
		// 存储
		int k = n;
		// 排序
		sort(A[1].begin(), A[1].end(), cmp);
		sort(A[2].begin(), A[2].end(), cmp);
		sort(A[3].begin(), A[3].end(), cmp);
		// 处理
		while(k--) {
			for(int i = 1; i <= 3; i++) {
				ans += A[i][1];
			}
		}
		// 输出
		printf("%d\n", ans);
	}
	return 0;
}