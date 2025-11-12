#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;

int T;
int n;

struct Node {
	int a, b, c;
}q[N];

bool Acmp(Node x, Node y) {
	return x.a > y.a;
}

int ans = 0;
int n2 = 0;
map<tuple<int, int, int>, int> mp;
int p1, p2, p3;
//unordered_map<int, int> mp;

void dfs(int k, int s, int q1, int q2, int q3) {
	
	//printf("k:%d s:%d q1:%d q2:%d q3:%d\n", k, s, q1, q2, q3);
	
	if (k == n + 1) {
		ans = max(ans, s);
		return ;
	}
	if (s <= mp[{q1, q2, q3}] && s) return ;
	mp[{q1, q2, q3}] = s;
	if (q1 < n2) dfs(k + 1, s + q[k].a, q1 + 1, q2, q3);
	else {
		if (s < p1) return ;
		p1 = s;
	}
	if (q2 < n2) dfs(k + 1, s + q[k].b, q1, q2 + 1, q3);
	else {
		if (s < p2) return ;
		p2 = s;
	}
	if (q3 < n2) dfs(k + 1, s + q[k].c, q1, q2, q3 + 1);
	else {
		if (s < p3) return ;
		p3 = s;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	while (T--) {
	
		bool A = true;
	
		cin >> n;
		n2 = n / 2;
		for (int i = 1; i <= n; ++i) {
			cin >> q[i].a >> q[i].b >> q[i].c;
			
			if (q[i].b || q[i].c) A = false;
		}
		
		if (A) {
			
			sort(q + 1, q + n + 1, Acmp);
			
			int tmp = 0;
			
			for (int i = 1; i <= n; ++i) {
				if (tmp < n2) {
					ans += q[i].a;
					tmp++;
				}
				else break; 
			}
			
			cout << ans << "\n";
		} else {
			mp.clear();
			ans = 0;
			dfs(1, 0, 0, 0, 0);
			cout << ans << "\n";
		}
	}
	
	return 0;
}
