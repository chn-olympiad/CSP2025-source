#include<bits/stdc++.h>
#define N 10005
using namespace std;
string s[N][2];
int n, q;
bool check(string &s1, string &s2, int l1, int l2, int s){
	for(int i = 1;i <= s;i++){
		if(s1[l1 + i - 1] != s2[l2 + i - 1])return 0;
	}
	return 1;
}
int dfs(string str, int dep, string &lst){
	//cout << str << ' ' << lst << " z\n";
	if(str == lst)return 1;
	if(dep > 0)return 0;
	int ans = 0;
	for(int i = 0;i < str.size();i++){
		for(int j = 1;j <= n;j++){
			//cout << s[j][0] << ' ' << i << '\n';
			if(i + s[j][0].size() <= str.size()){
				if(check(str, s[j][0], i, 0, s[j][0].size())){
					string str2 = str;
					for(int k = 0;k < s[j][0].size();k++){
						str2[k + i] = s[j][1][k];
					}
					//cout << str2 << '\n';
					int v = dfs(str2, dep + 1, lst);
					//cout << v << 'a';
					ans += v;
				}
			}
		}
	}
	//cout << ans << '\n';
	return ans;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s[i][0] >> s[i][1];
	}
	for(int i = 1;i <= q;i++){
		string t1, t2;
		cin >> t1 >> t2;
		cout << dfs(t1, 0, t2) << '\n';
	}
	return 0;
}
