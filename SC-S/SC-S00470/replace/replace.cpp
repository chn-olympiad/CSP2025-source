//long long + scanf!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//dfs
#include <bits/stdc++.h>
using namespace std;
long long n, q;
string s[2001][2];
long long bfs(string qs, string as) {
	int ans = 0;
	queue <string> q;
	q.push(qs);
	while(!q.empty()){
		string now = q.front();
		q.pop();
		if (now == as) {
			ans++;
		}
		for(int i = 0; i < n; i++) {
			string te = now;
			string qian = "";
			while(te.find(s[i][0]) != string::npos){
				//cout << "find : " << te.find(s[i][0]) << " " << te << " ";
				qian = te.substr(0, te.find(s[i][0]));
				te.replace(te.find(s[i][0]), s[i][0].size(), s[i][1]);
				if (te == as || qian + te == as) {
					ans++;
					break;
				}
				q.push(qian + te);
				te.replace(0, s[i][0].size() + te.find(s[i][0]) + 1, "");
				//cout << "t : " << te << endl;
				
				
			}
		}
	}
	return ans;
}
int main() {
	freopen("relpace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	//cout << 1;
	for(int i = 0; i < n; i++) {
		//cout << s[i][0] << " " << s[i][1];
	}
	while(q--) {
		string qs, as;
		cin >> qs >> as;
		cout << bfs(qs, as) << endl;
	}
	return 0;
} 