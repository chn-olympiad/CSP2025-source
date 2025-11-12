#include <bits/stdc++.h>
using namespace std;
int n, m, a1, a;
priority_queue<int> pq;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	cin >> a1;
	pq.push(a1);
	for (int i = 1; i < n*m; i++){
		cin >> a;
		pq.push(a);
	}
	for (int i = 1; i <= n*m; i++){
		int k = pq.top();
		pq.pop();
		if (k == a1){
			int l = ceil(i*1.0/m);
			int h = i % n;
			if (l % 2 == 0){
				h = n + 1 - h;
			}
			if (i % n == 0){
				h = n;
			}
			cout << l << " " << h;
			return 0;
		}
	}
}
