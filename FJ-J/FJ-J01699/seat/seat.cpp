#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, grade, tmp, num;
priority_queue<int> q;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1;i <= n * m; i++){
		cin >> tmp;
		if (i == 1) grade = tmp;
		q.push(tmp);
	}
	num = 0;
	while (!q.empty()) {
		num++;
		if (q.top() == grade){
			cout << (num - 1) / n + 1 << ' ';
			if (((num - 1) / n + 1) % 2) {
				cout << 1 + (num - 1) % n;
			} else {
				cout << n - (num - 1) % n;
			}
			cout << endl;
			break;
		};
		q.pop();
	}
	return 0;
}
