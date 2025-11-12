#include <bits/stdc++.h>
#include <windows.h>
#define _1 first
#define _2 second
#define pii pair<int, int>
#define deb(x) clog << #x << " : " << x << " "
#define debn(x) clog << #x << " : " << x << "\n"
using namespace std;
typedef long long ll;
const int N = 85;
const int mod = 998244353, iinf = 0x3f3f3f3f, X = -1, O = 1;
const char x = 'x', o = 'o';
int n;
char s[N][N];
bool vis[N][N];
inline void quit(int retval = 0, char *cmd = "pause") {
	system("pause");
	exit(retval);
}
inline bool crt(int r, int c) {
	return r >= 1 && r <= n && c >= 1 && c <= n;
}
int _1(int r, int c) {
	char p = s[r][c];
	if (p == '+') 
		return 0;
	queue<pii> q;
	int cnt = -1;
	q.push({r, c});
	memset(vis, 0, sizeof(vis));
	vis[r][c] = 1;
	while (!q.empty()) {
		pii u = q.front();
		q.pop();
		cnt ++;
		int x = u._1 - 1, y = u._2;
		if (crt(x, y) && !vis[x][y] && s[x][y] == p) {
			cnt ++;
			vis[x][y] = 1;
			q.push({x, y});
		}
		x = u._1 + 1, y = u._2;
		if (crt(x, y) && !vis[x][y] && s[x][y] == p) {
			cnt ++;
			vis[x][y] = 1;
			q.push({x, y});
		}
		return cnt >= 5 ? (p == o ? O : X) : 0;
	}
	return cnt >= 5 ? (p == o ? O : X) : 0;
}
int _2(int r, int c) {
	char p = s[r][c];
	if (p == '+') 
		return 0;
	queue<pii> q;
	int cnt = -1;
	q.push({r, c});
	memset(vis, 0, sizeof(vis));
	vis[r][c] = 1;
	while (!q.empty()) {
		pii u = q.front();
		q.pop();
		cnt ++;
		int x = u._1, y = u._2 - 1;
		if (crt(x, y) && !vis[x][y] && s[x][y] == p) {
			cnt ++;
			vis[x][y] = 1;
			q.push({x, y});
		}
		x = u._1, y = u._2 + 1;
		if (crt(x, y) && !vis[x][y] && s[x][y] == p) {
			cnt ++;
			vis[x][y] = 1;
			q.push({x, y});
		}
		return cnt >= 5 ? (p == o ? O : X) : 0;
	}
	return cnt >= 5 ? (p == o ? O : X) : 0;
}
int _3(int r, int c) {
	char p = s[r][c];
	if (p == '+') 
		return 0;
	queue<pii> q;
	int cnt = -1;
	q.push({r, c});
	memset(vis, 0, sizeof(vis));
	vis[r][c] = 1;
	while (!q.empty()) {
		pii u = q.front();
		q.pop();
		cnt ++;
		int x = u._1 - 1, y = u._2 - 1;
		if (crt(x, y) && !vis[x][y] && s[x][y] == p) {
			cnt ++;
			vis[x][y] = 1;
			q.push({x, y});
		}
		x = u._1 + 1, y = u._2 + 1;
		if (crt(x, y) && !vis[x][y] && s[x][y] == p) {
			cnt ++;
			vis[x][y] = 1;
			q.push({x, y});
		}
		return cnt >= 5 ? (p == o ? O : X) : 0;
	}
	return cnt >= 5 ? (p == o ? O : X) : 0;
}
int _4(int r, int c) {
	char p = s[r][c];
	if (p == '+') 
		return 0;
	queue<pii> q;
	int cnt = -1;
	q.push({r, c});
	memset(vis, 0, sizeof(vis));
	vis[r][c] = 1;
	while (!q.empty()) {
		pii u = q.front();
		q.pop();
		cnt ++;
		int x = u._1 - 1, y = u._2 + 1;
		if (crt(x, y) && !vis[x][y] && s[x][y] == p) {
			cnt ++;
			vis[x][y] = 1;
			q.push({x, y});
		}
		x = u._1 + 1, y = u._2 - 1;
		if (crt(x, y) && !vis[x][y] && s[x][y] == p) {
			cnt ++;
			vis[x][y] = 1;
			q.push({x, y});
		}
		return cnt >= 5 ? (p == o ? O : X) : 0;
	}
	return cnt >= 5 ? (p == o ? O : X) : 0;
}
void check() {
	for (int i = 1; i <= n; i ++) 
		for (int j = 1; j <= n; j ++) 
			if (_1(i, j) == O || _2(i, j) == O || _3(i, j) == O || _4(i, j) == O) {
				cout << o << " win!" << endl;
				quit();
			} else if (_1(i, j) == X || _2(i, j) == X || _3(i, j) == X || _4(i, j) == X) {
				cout << x << " win!" << endl;
				quit();
			}
}
void cktie() {
	for (int i = 1; i <= n; i ++) 
		for (int j = 1; j <= n; j ++) 
			if (s[i][j] == '+') 
				return;
	cout << "Tie!" << endl;
	quit();
}
void print() {
	system("cls");
	for (int i = 0; i <= n; i ++) {
		for (int j = 0; j <= n; j ++) 
			cout << s[i][j];
		cout << endl;
	}
}
void input(const char p) {
	int r, c;
	inputrc:
	cout << p << "'s R and C:" << endl;
	cin >> r >> c;
	if (crt(r, c) && s[r][c] == '+') 
		s[r][c] = p;
	else {
		cout << "Invalid R or C!" << endl;
		goto inputrc;
	}
}
void solve() {
	print();
	input(o);
	print();
	check();
	cktie();
	input(x);
	print();
	check();
	cktie();
}
signed main() {
//	freopen("base.in", "r", stdin);
//	freopen("base.out", "w", stdout);
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = iinf;
	memset(s, '+', sizeof s);
	inputn:
	cout << "Input chessboard size:" << endl;
	cin >> n;
	if (n < 5 || n > 78) {
		cout << "Invalid size!" << endl;
		goto inputn;
	}
	for (int i = 0; i <= n; i ++) {
		s[i][0] = i + '0';
		s[0][i] = i + '0';
	}
	while (t --) 
		solve();
	return 0;
}
/*
Made by Luogu_uid:1283849
2025/11/1 17:19 
Version = Beta 1.0
(In this morning, you can find a chess.cpp, too. That one is mine, and it's version is Alpha 1.2 .)
*/
