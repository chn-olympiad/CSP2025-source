#include<bits/stdc++.h>
#define ll long long
const int N = 20;
using namespace std;

int n, m, my_score;
vector <int> v;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}

	my_score = v[0];
	sort(v.begin(), v.end(), cmp);

	bool flag = true;
	int x = 1, y = 1, cnt = 0;

	while(v[cnt] != my_score) {
		cnt++;
		if(flag) {
			if(y == n) {
				x++;
				flag = false;
			}
			else y++;
		}
		else {
			if(y == 1) {
				x++;
				flag = true;
			}
			else y--;
		}
	}

	cout << x << ' ' << y;

	return 0;
}
