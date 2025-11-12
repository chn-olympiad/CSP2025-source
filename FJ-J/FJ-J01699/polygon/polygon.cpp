#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, tmp, a, b, c;
priority_queue<int> q;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> tmp;
		q.push(tmp);
	}
	if (q.top() == 1) {
		cout << (n * n + 2 - 3 * n) / 2;
		return 0;
	}
	if (n == 3){
		a = q.top(); q.pop();
		b = q.top(); q.pop();
		c = q.top(); q.pop();
		if ( a + b + c > 2 * a){
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	}
	return 0;
}
