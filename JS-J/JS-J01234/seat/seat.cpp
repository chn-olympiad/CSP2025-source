#include<bits/stdc++.h>
using namespace std;
int score[109];
int location, lie, hang;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int k = n * m, cnt = 2 * n;
	for(int i = 1; i <= k; ++i) cin >> score[i];
	int a = score[1];
	sort(score + 1, score + k + 1, greater<int>());
	for(int i = 1; i <= k; ++i) {
		if(score[i] == a) {
			location = i;
			break;
		}
	}
	location % cnt <= n ? hang = location % cnt : hang = n - location % n + 1;
	location % cnt <= n ? lie = location / cnt * 2 + 1 : lie = location / cnt * 2 + 2;
	cout << lie << " " << hang;
	return 0;
}
