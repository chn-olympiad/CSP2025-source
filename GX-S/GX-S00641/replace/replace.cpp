#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 6;
int ans = 0;
string s[N][3];
void sovle(string s1,string s2,string t1,string t2){
	int len_s = s1.size(),len_t = t1.size();
	for (int i = 0; i < len_t; ++i){
		int j = i + len_s - 1;
		if (j >= len_t) break;
		string t,tt;
		for (int k = i; k <= j; ++k){
			t += t1[k];
			tt += t2[k];
		}
		if (t == s1 && tt == s2){
			if (t1.substr(0,i) == t2.substr(0,i) && t1.substr(j + 1,len_t - j - 1) == t2.substr(j + 1,len_t - j - 1)){
				++ans;
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i){
		cin >> s[i][1] >> s[i][2];
	}
	while(q--){
		ans = 0;
		string t1,t2;
		cin >> t1 >> t2;
		for (int i = 1; i <= n; ++i){
			sovle(s[i][1],s[i][2],t1,t2);
		}
		cout << ans << '\n';
	}
	return 0;
}
