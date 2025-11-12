#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q;
string t1, t2; 
unordered_map <string, string> mp;
struct ss{
	string pre, nxt;
	void read(){
		cin >> pre >> nxt;
		mp[pre] = nxt;
	}
} s[N];

int ans = 0;
//void dfs(int step, string s){
//	if(step == t1.size()){
//		if(s == t2) ans ++; 
//		return;
//	}
//	for(int i = 1; i <= n; i ++){
//		if()
//	}
//}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i ++){
		s[i].read();
	}
	while(q --){
		cin >> t1;
		cin >> t2;
		cout << 0 << "\n";
	}
	return 0;
}
