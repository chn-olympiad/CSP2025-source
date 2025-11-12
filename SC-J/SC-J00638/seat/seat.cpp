#include<bits/stdc++.h>
using namespace std;

const int N = 15;

struct node {
	int id, num;
	int sx, sy;
}stu[N * N];
int n, m;

bool cmp(node x, node y) {
	return x.num > y.num;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> stu[i].num;
		stu[i].id = i;
	}
	sort(stu + 1, stu + 1 + n * m, cmp);
	int k = n * m, top = 0;
	int x = 1, y = 1;
	while(k--) {
		stu[++top].sx = x;
		stu[top].sy = y;
		if(y & 1) {
			x++;
			if(x == n + 1) x = n, y++;
		}
		else if(!(y & 1)) {
			x--;
			if(x == 0) x = 1, y++;
		}
	}
	for(int i = 1; i <= n * m; i++) {
		if(stu[i].id == 1) {
			cout << stu[i].sy << ' ' << stu[i].sx << '\n';
			return 0;
		}
	}
}