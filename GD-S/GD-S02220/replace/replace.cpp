#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int maxn = 5e6 + 5;
int n, q;
string s[maxn], t[maxn];

bool check(string s, string s2, string t, string t2){
	int ls = s.length(), lt = t.length(), idx = -1;
	for(int i = 0; i < ls-lt+1; i++){
		bool flg = 1;
		for(int j = i; j < i+lt; j++){
//			cout << i << ' ' << t[j-i] << ' ' << s[j] << endl;
			if(t[j-i] != s[j]){
				flg = 0;
				break;
			}
		}
		if(flg){
			idx = i;
			break;
		}
	} 
	if(idx == -1) return 0;
//	cout << idx << ' '<< s.substr(0, idx) << ' ' << s.substr(idx+lt) << ' ' << t2 << endl;
	string tmp = s.substr(0, idx) + t2 + s.substr(idx+lt);
//	cout << tmp << endl;
	return tmp == s2; 
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s[i] >> t[i];
//		cout << "aaaa" << s[i] << endl;
	}
	for(int i = 1; i <= q; i++){
		int ans = 0;
		string s1, s2; cin >> s1 >> s2;
		for(int j = 1; j <= n; j++){
			ans += check(s1, s2, s[j], t[j]);
		}
		cout << ans << endl;
	}
	return 0;
}
