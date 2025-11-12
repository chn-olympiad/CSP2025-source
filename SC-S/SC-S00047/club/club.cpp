#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

namespace IO {
	const int MAX_SIZE = 1 << 20;
	
	char buf[MAX_SIZE], *p1 = buf, *p2 = buf;
	char gc() {
		return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAX_SIZE, stdin), p1 == p2) ? EOF : *p1++;
	}
	template <typename T> void R(T &x) {
		x = 0;
		bool sign = 0;
		char ch = gc();
		while (ch < '0' || ch > '9') sign |= ch == '-', ch = gc();
		while (ch >= '0' && ch <= '9') {
			x = (x << 3) + (x << 1) + (ch ^ 48);
			ch = gc();
		}
		if (sign) x = -x;
	}
}
using IO::R;

const int maxn = 1e5 + 5;

struct node{
	int id, val1, val2, now;
	bool operator <(const node &a) const{
		return val1 - val2 > a.val1 - a.val2;
	}
};

struct node1{
	int id, val;
	bool operator <(const node1 &a) const{
		return val > a.val;
	}
};

priority_queue<node>q[4];
int n;
node1 a[maxn][4];
void solve() {
	int T;
	R(T);
	while (T--) {
		R(n);
		int half = n >> 1;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= 3; ++j)
				R(a[i][j].val), a[i][j].id = j;
			sort(a[i] + 1, a[i] + 4);
		}
		for(int i = 1; i <= n; ++i) q[a[i][1].id].push({i, a[i][1].val, a[i][2].val, 1});
		int pos = 0;
		for(int i = 1; i <= 3; ++i) if(q[i].size() > half) pos = i;
		if(pos){
			while(q[pos].size() > half){
				auto tmp = q[pos].top();
				q[pos].pop();
				q[a[tmp.id][2].id].push({tmp.id, tmp.val1, tmp.val2, 2});
			}
		}
		int ans = 0;
		while(!q[1].empty()) ans += q[1].top().now == 1 ? q[1].top().val1 : q[1].top().val2, q[1].pop();
		while(!q[2].empty()) ans += q[2].top().now == 1 ? q[2].top().val1 : q[2].top().val2, q[2].pop();
		while(!q[3].empty()) ans += q[3].top().now == 1 ? q[3].top().val1 : q[3].top().val2, q[3].pop();
		printf("%d\n", ans);
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	solve();
	return 0;
}