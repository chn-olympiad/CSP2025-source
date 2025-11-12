#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, Q, ans, len, cd[N];
string s[N][2], s1, s2;
void dfs(string ds, int step){
	if(step > 1) return;
	if(ds == s2) ans++;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < len;j++){
			int wz = ds.find(s[i][0]);
			if(wz == j) dfs(ds.substr(0, j) + s[i][1] + ds.substr(j + cd[i], len - j - cd[i]), step + 1);
		}
	}
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
//	freopen("replace4.in", "r", stdin);
//	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> Q;
	for(int i = 1;i <= n;i++){
		cin >> s[i][0] >> s[i][1];
		cd[i] = s[i][0].size();
	}
	while(Q--){
		cin >> s1 >> s2;
		len = s1.size(), ans = 0, dfs(s1, 0);
		cout << ans << "\n";
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
