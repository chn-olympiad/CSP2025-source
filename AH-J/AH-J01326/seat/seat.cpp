#include <bits/stdc++.h>
using namespace std;

int n, m, l;
int a[105];
pair<int, int> pos[105];

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> a[i];
	for(int i = 1; i <= n * m; i++)
		if(a[i] >= a[1]) l++;
	int now = 1;
	for(int i = 1; i <= m; i++) {
		if(i % 2 == 1) {
			for(int j = 1; j <= n; j++)
				pos[now].first = i, pos[now].second = j, now++;
		} else {
			for(int j = n; j >= 1; j--)
				pos[now].first = i, pos[now].second = j, now++;
		}
	}
	cout << pos[l].first << " " << pos[l].second << endl;
	return 0;
}
