#include <bits/stdc++.h>
using namespace std;
string s; int n;
priority_queue<char> que; 
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	s = ' ' + s;
	int n = s.size() - 1;
	for(int i = 1; i <= n; i++){
		char c = s[i];
		if(c >= '0' && c <= '9') que.push(c);
	}
	while(!que.empty()){
		cout << que.top();
		que.pop();
	}
	return 0;
}
