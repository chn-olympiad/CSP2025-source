#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int t, n;
int a[N][3], Tmp[3];
pair<int, int> ty[N][3];
struct node {
	int id1, id2, a, b;
}p[N];

int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || '9' < ch) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9') x = x * 10 + (ch - '0'), ch = getchar();
	return x * f;
}

bool cmp(node a, node b) {
	return a.a - a.b < b.a - b.b;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	t = read();
	
	while (t --) {
		memset(Tmp, 0, sizeof Tmp);
		
		n = read();
		for (int i = 1; i <= n; i ++) {
			a[i][0] = read();
			a[i][1] = read();
			a[i][2] = read();
		} 
		
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j < 3; j ++) ty[i][j] = make_pair(a[i][j], j);
			sort(ty[i], ty[i] + 3);
			p[i] = (node){ty[i][2].second, ty[i][1].second, ty[i][2].first, ty[i][1].first};
		}
		sort(p + 1, p + 1 + n, cmp);
		
		int Sum = 0;
		for (int i = 1; i <= n; i ++) {
			Tmp[p[i].id1] ++;
			Sum += p[i].a;
		}
		
		for (int i = 1; i <= n; i ++) {
			int Mx = max(Tmp[0], max(Tmp[1], Tmp[2]));
			int tMx = 0;
			for (int j = 0; j < 3; j ++)
				if (Mx == Tmp[j]) tMx = j;
			if (Mx > n / 2 && p[i].id1 == tMx) {
				Tmp[p[i].id1] --;
				Tmp[p[i].id2] ++;
				Sum -= p[i].a - p[i].b;
			}
		}
		
		printf("%d\n", Sum);
	}
	
	return 0;
} 
