#include<bits/stdc++.h>
using namespace std;

template<typename T> void qr(T &x) {
	x = 0; char c = getchar(); int f = 1;
	for (; !isdigit(c); c = getchar()) if (c == '-') {
		f = -1;
	}
	for (; isdigit(c); c = getchar()) {
		x = x * 10 + (c - '0');
	}
	x *= f;
}

template<typename T> void qw(T x) {
	if (x < 0) {
		putchar('-');
	}
	if (x > 9) {
		qw(x / 10);
	}
	putchar(x % 10 + '0');
}

typedef long long LL;
const int N = 1e5 + 10;

struct node {
	int x;   // ¬˙“‚∂» 
	int id;   // »À 
};

priority_queue<node> Q[4];
bool v[N];
node a[N][4];

bool operator<(node na, node nb) {
	return na.x > nb.x;
}

bool cmp(node na, node nb) {
	return na.x > nb.x;
}

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	while (T --) {
		int n;
		cin >> n;
		
		for (int i = 1; i <= n; i ++) {
			v[i] = 0;
		}
		
		for (int i = 1; i <= 3; i ++) {
			while (!Q[i].empty()) {
				Q[i].pop();
			}
		}
		
		LL ans = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= 3; j ++) {
				cin >> a[i][j].x;
				a[i][j].id = j;
			}
			sort(a[i] + 1, a[i] + 3 + 1, cmp);
			Q[a[i][1].id].push({a[i][1].x - a[i][2].x, i});
		}
		
		for (int i = 1; i <= 3; i ++) {
			while (Q[i].size() > n / 2) {
				node no = Q[i].top(); 
				Q[i].pop();
				Q[a[no.id][2].id].push({0, no.id});
			}
		}
		
		for (int i = 1; i <= 3; i ++) {
			while (!Q[i].empty()) {
				node no = Q[i].top(); Q[i].pop();
				ans += no.x + a[no.id][2].x;
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}
