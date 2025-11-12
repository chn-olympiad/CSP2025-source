#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
int main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	priority_queue <int> q;
	int R;
	for(int i = 1; i <= n * m; i++) {
		int x; cin >> x;
		if(i == 1) R = x;
		q.push(x);
	}
	for(int i = 1; i <= n * m; i++) {
		int c, r;
		if(i == 0) c = 1, r = 1;
		else {
			if(((i - 1) / n) & 1) c = n - ((i - 1) % n);
			else c = (i - 1) % n + 1;
			r = (i - 1) / n + 1;
		}
		if(q.top() == R) {
//			cout << i << " ";
			cout << r << " " << c;
			break;
		}
		q.pop();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
