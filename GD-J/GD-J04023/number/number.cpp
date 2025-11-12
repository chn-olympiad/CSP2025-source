#include <bits/stdc++.h>
#define inc(i, l, r) for(int i = l; i <= r; ++i)
#define dec(i, l, r) for(int i = l; i >= r; --i) 
using namespace std;

string s;
priority_queue < int > pq;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> s;
	
	inc(i, 0, s.length() - 1) {
		if(s[i] >= '0' && s[i] <= '9') {
			pq.push(s[i] - '0');
		}
	}
	while(!pq.empty()) {
		cout << pq.top();
		pq.pop();
	}
	return 0; 
}
