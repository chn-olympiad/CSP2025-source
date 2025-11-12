/*
so? CSP-J 红橙黄黄?
666
来luogu找我：1023865
*/
#include <algorithm>
#include <cstring>
#include <iostream>
#define madd(__A__, __B__) (((__A__) += (__B__)) >= mod && ((__A__) -= mod))

using namespace std;

constexpr int N = 5010, mod = 998244353;
int n, a[N], b[N][N], f[N][N], p2[N], ans;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < N; j++)
			b[i][j] = b[i - 1][j] + (a[i] == j);
	for (int i = 1; i <= n; i++)
		for (int j = N - 2; ~j; j--)
			madd(b[i][j], b[i][j + 1]);
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		memcpy(f[i], f[i - 1], sizeof(int) * N);
		for (int j = a[i]; j < N; j++)
			madd(f[i][j], f[i - 1][j - a[i]]);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < N; j++)
			madd(f[i][j], f[i][j - 1]);
	p2[0] = 1;
	for (int i = 1; i < N; i++)
		(p2[i] = p2[i - 1] << 1) >= mod && (p2[i] -= mod);
	for (int i = 3; i <= n; i++) {
		int temp = p2[i - 1];
		madd(temp, mod - f[i - 1][a[i]]);
		madd(temp, mod - b[i - 1][a[i] + 1]);
		madd(ans, temp);
	}
	cout << ans << endl;
	return 0;
}

/*
放份扫雷（考场现打的）

#include <chrono>
#include <conio.h>
#include <iostream>
#include <queue>
#include <random>
#include <utility>
#include <windows.h>

using namespace std;

using pii = pair<int, int>;

mt19937 rd(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());

int getint(int l, int r) {
	return rd() % (r - l + 1) + l;
}

constexpr bool DEBUG = false;
constexpr int N = 100, M = 100;
constexpr int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
constexpr int dx2[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy2[] = {0, 1, 0, -1, 1, -1, 1, -1};
int n, m, ck;
char a[N][M];
int b[N][M], c[N][M], cx, cy, mk;

void init() {
	system("cls");
	cout << "Choose the difficulty: 1) Simple  2) Midium  3) Hard  4) Self" << endl;
	char ch;
	do ch = getch();
	while (ch != '1' && ch != '2' && ch != '3' && ch != '4' && int(ch) != 3);
	if (int(ch) == 3) {
		system("pause");
		exit(0);
	}
	if (ch == '1') n = 10, m = 10, ck = 20;
	else if (ch == '2') n = 20, m = 20, ck = 70;
	else if (ch == '3') n = 20, m = 40, ck = 150;
	else {
		do {
			cout << "Rows: ";
			cin >> n;
			if (n <= 0 || n > 100) {
				cout << "Invalid n (0 < n <= 100)!" << endl;
				continue;
			} else break;
		} while (true);
		do {
			cout << "Cols: ";
			cin >> m;
			if (m <= 0 || m > 100) {
				cout << "Invalid m (0 < m <= 100)!" << endl;
				continue;
			} else break;
		} while (true);
		do {
			cout << "Count: ";
			cin >> ck;
			if (ck < 0 || ck > n * m) {
				cout << "Invaild ck (0 <= ck <= n * m = " << n * m << ")!" << endl;
				continue;
			} else break;
		} while (true);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			b[i][j] = 0, c[i][j] = 0;
	int cur = 0;
	while (cur < ck) {
		int tx = getint(0, n - 1), ty = getint(0, m - 1);
		if (!b[tx][ty]) {
			b[tx][ty] = -1;
			cur++;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (b[i][j] == -1) {
				for (int k = 0; k < 8; k++) {
					int tx = i + dx2[k], ty = j + dy2[k];
					if (tx < 0 || tx >= n || ty < 0 || ty >= m || b[tx][ty] == -1) continue;
					b[tx][ty]++;
				}
			}
		}
	cx = 0, cy = 0;
}

void refresh() {
	system("cls");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cx == i && cy == j) cout << '>';
			else cout << ' ';
			if (c[i][j] == 0) cout << '*';
			else if (c[i][j] == 1) cout << (b[i][j] > 0 ? char(b[i][j] + '0') : '.');
			else cout << '$';
		}
		if (DEBUG) {
			cout << " |";
			for (int j = 0; j < m; j++) {
				if (cx == i && cy == j) cout << '>';
				else cout << ' ';
				if (b[i][j] >= 0) cout << (b[i][j] > 0 ? char(b[i][j] + '0') : '.');
				else cout << '$';
			}
		}
		cout << endl;
	}
	cout << "have: " << ck << "   mark: " << mk << endl;
}

void gameover() {
	system("cls");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << ' ' << (b[i][j] == -1 ? '&' : '.');
		cout << endl;
	}
	cout << "gameover!" << endl;
	Sleep(500);
	system("pause");
	init();
}

void expand(int sx, int sy) {
	queue<pii> q;
	c[sx][sy] = 1;
	q.push({sx, sy});
	while (!q.empty()) {
		pii u = q.front(); q.pop();
		if (b[u.first][u.second] == 0) {
			for (int i = 0; i < 8; i++) {
				int tx = u.first + dx2[i], ty = u.second + dy2[i];
				if (tx < 0 || tx >= n || ty < 0 || ty >= m || c[tx][ty]) continue;
				q.push({tx, ty});
				c[tx][ty] = 1;
			}
		}
	}
}

bool check(int sx, int sy) {
	if (c[sx][sy] != 1) return false;
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int tx = sx + dx2[i], ty = sy + dy2[i];
		if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
		if (c[tx][ty] == 2) cnt++;
	}
	if (b[sx][sy] == cnt) {
		for (int i = 0; i < 8; i++) {
			int tx = sx + dx2[i], ty = sy + dy2[i];
			if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
			if (!c[tx][ty]) {
				if (b[tx][ty] == -1) {
					gameover();
					return true;
				}
				expand(tx, ty);
			}
		}
		return true;
	}
	return false;
}

bool checkwin() {
	bool flag1 = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			flag1 = flag1 && (c[i][j] == 2) == (b[i][j] == -1);
	bool flag2 = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			flag2 = flag2 && (c[i][j] == 1) == (b[i][j] >= 0);
	return flag1 || flag2;
}

void gamewin() {
	system("cls");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << ' ' << (b[i][j] == -1 ? '&' : '.');
		cout << endl;
	}
	cout << "you win!" << endl;
	Sleep(1000);
	system("pause");
	init();
}

int main() {
	init();
	refresh();
	while (true) {
		char ch = getch();
		if (ch == 'W' || ch == 'w') {
			if (!cx) continue;
			cx--;
		} else if (ch == 'S' || ch == 's') {
			if (cx == n - 1) continue;
			cx++;
		} else if (ch == 'A' || ch == 'a') {
			if (!cy) continue;
			cy--;
		} else if (ch == 'D' || ch == 'd') {
			if (cy == m - 1) continue;
			cy++;
		} else if (int(ch) == 13) {
			if (c[cx][cy] == 2) {
				c[cx][cy] = 0;
			} else if (b[cx][cy] == -1) {
				gameover();
			} else if (c[cx][cy] == 0) {
				expand(cx, cy);
			} else if (!check(cx, cy)) continue;
		} else if (int(ch) == 32) {
			if (c[cx][cy] == 0) c[cx][cy] = 2, mk++;
			else if (c[cx][cy] == 2) c[cx][cy] = 0, mk--;
			else continue;
		} else if (int(ch) == 3) {
			system("pause");
			return 0;
		} else if (int(ch) == 27) {
			init();
		} else continue;
		refresh();
		if (checkwin())
			gamewin();
	}
	return 0;
}
*/
