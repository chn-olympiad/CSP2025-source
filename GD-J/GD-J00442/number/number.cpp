#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	int len = s.size();
	priority_queue <int> q;
	for(int i = 0; i < len; i++) {
		if(isdigit(s[i])) q.push(s[i] ^ 48);
	}
	while(!q.empty()) {
		cout << q.top();
		q.pop();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
