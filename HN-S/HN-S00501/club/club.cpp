#include <bits/stdc++.h>

using namespace std;

template <typename T>
inline void read(T& x) {
	x = 0;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) ;
	for (;  isdigit(ch); ch = getchar()) x = x * 10 + (ch - '0');
}

using P = pair<int, int>;

int t;
int n;
int a[100005][3];
int p[100005];
int cnt[3];
priority_queue<P> q[3][3];
int res;

bool work1(int x, int y) {
	if (cnt[y] >= n / 2)
		return false;
	auto& cur = q[x][y];
	while (!cur.empty()) {
		const int delta = cur.top().first, id = cur.top().second;
		cur.pop();
		if (p[id] != x)
			continue;
		if (delta <= 0) {
			cur.emplace(delta, id);
			break;
		}
		p[id] = y;
		cnt[x]--;
		cnt[y]++;
		for (int i = 0; i < 3; i++)
			if (i != y)
				q[y][i].emplace(a[id][i] - a[id][y], id);
		res += delta;
		return true;
	}
	return false;
}

bool work2(int x, int y) {
	auto& prv = q[x][y], & nxt = q[y][x];
	while (!prv.empty() && p[prv.top().second] != x)
		prv.pop();
	while (!nxt.empty() && p[nxt.top().second] != y)
		nxt.pop();
	if (!prv.empty() && !nxt.empty() && prv.top().first + nxt.top().first > 0) {
		res += prv.top().first + nxt.top().first;
		const int prvid = prv.top().second, nxtid = nxt.top().second;
		prv.pop(), nxt.pop();
		p[prvid] = y, p[nxtid] = x;
		for (int i = 0; i < 3; i++) {
			if (i != y)
				q[y][i].emplace(a[prvid][i] - a[prvid][y], prvid);
			if (i != x)
				q[x][i].emplace(a[nxtid][i] - a[nxtid][x], nxtid);
		}
		return true;
	}
	return false;
}

bool work3(int x, int y, int z) {
	auto& prv = q[x][y], & cur = q[y][z], & nxt = q[z][x];
	while (!prv.empty() && p[prv.top().second] != x)
		prv.pop();
	while (!cur.empty() && p[cur.top().second] != y)
		cur.pop();
	while (!nxt.empty() && p[nxt.top().second] != z)
		nxt.pop();
	if (!prv.empty() && !cur.empty() && !nxt.empty() && prv.top().first + cur.top().first + nxt.top().first > 0) {
		res += prv.top().first + cur.top().first + nxt.top().first;
		const int prvid = prv.top().second, curid = cur.top().second, nxtid = nxt.top().second;
		prv.pop(), cur.pop(), nxt.pop();
		p[prvid] = y, p[curid] = z, p[nxtid] = x;
		for (int i = 0; i < 3; i++) {
			if (i != y)
				q[y][i].emplace(a[prvid][i] - a[prvid][y], prvid);
			if (i != z)
				q[z][i].emplace(a[curid][i] - a[curid][z], curid);
			if (i != x)
				q[x][i].emplace(a[nxtid][i] - a[nxtid][x], nxtid);
		}
		return true;
	}
	return false;
}

bool work4(int x, int y, int z) {
	if (cnt[z] >= n / 2)
		return false;
	auto& prv = q[x][y], & cur = q[y][z];
	while (!prv.empty() && p[prv.top().second] != x)
		prv.pop();
	while (!cur.empty() && p[cur.top().second] != y)
		cur.pop();
	if (!prv.empty() && !cur.empty() && prv.top().first + cur.top().first > 0) {
		res += prv.top().first + cur.top().first;
		const int prvid = prv.top().second, curid = cur.top().second;
		prv.pop(), cur.pop();
		p[prvid] = y, p[curid] = z;
		cnt[x]--, cnt[z]++;
		for (int i = 0; i < 3; i++) {
			if (i != y)
				q[y][i].emplace(a[prvid][i] - a[prvid][y], prvid);
			if (i != z)
				q[z][i].emplace(a[curid][i] - a[curid][z], curid);
		}
		return true;
	}
	return false;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for (read(t); t--; ) {
		read(n);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++)
				read(a[i][j]);
			if (i <= n / 2) {
				p[i] = 0;
				cnt[0]++;
				q[0][1].emplace(a[i][1] - a[i][0], i);
				q[0][2].emplace(a[i][2] - a[i][0], i);
				res += a[i][0];
			}
			else {
				p[i] = 1;
				cnt[1]++;
				q[1][0].emplace(a[i][0] - a[i][1], i);
				q[1][2].emplace(a[i][2] - a[i][1], i);
				res += a[i][1];
			}
		}
		for (bool flag = true; flag; ) {
			flag = false;
			for (int i = 0; i < 3; i++) {
				for (int j = i + 1; j < 3; j++) {
					if (work1(i, j))
						flag = true;
					if (work1(j, i))
						flag = true;
					if (work2(i, j))
						flag = true;
				}
			}
			if (work3(0, 1, 2))
				flag = true;
			if (work3(0, 2, 1))
				flag = true;
			if (work3(1, 0, 2))
				flag = true;
			if (work3(1, 2, 0))
				flag = true;
			if (work3(2, 0, 1))
				flag = true;
			if (work3(2, 1, 0))
				flag = true;
			if (work4(0, 1, 2))
				flag = true;
			if (work4(0, 2, 1))
				flag = true;
			if (work4(1, 0, 2))
				flag = true;
			if (work4(1, 2, 0))
				flag = true;
			if (work4(2, 0, 1))
				flag = true;
			if (work4(2, 1, 0))
				flag = true;
		}
		printf("%d\n", res);
		cnt[0] = cnt[1] = cnt[2] = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				while (!q[i][j].empty())
					q[i][j].pop();
		res = 0;
	}
	return 0;
}
