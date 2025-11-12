#include <bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define vi vector<int>
#define sz(a) ((int)a.size())
using namespace std;
const int N = 210;
int a[N][N];
array<int, 2> p[N];
int b[N];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, tot = 0, cnt = 1;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> b[i];
		if(b[i] > b[1]) cnt++;
	}
	for(int j = 1; j <= m; j++) {
		if(j & 1) {
			for(int i = 1; i <= n; i++) {
				p[++tot] = {i, j}; 
				a[i][j] = tot;
			}
		}
		else {
			for(int i = n; i >= 1; i--) {
				p[++tot] = {i, j}; 
				a[i][j] = tot;
			}
		}
	}
	cout << p[cnt][1] << " " << p[cnt][0] << '\n';
	return 0;
}

