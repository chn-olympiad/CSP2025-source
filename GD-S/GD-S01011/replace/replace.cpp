#include<bits/stdc++.h>
#define int long long
#define N 500005
#define dbg(x) cerr<<#x<<" "<<x<<endl
using namespace std;
int n, q;
string s[N], t[N];
string S, T;
void read(){
	cin >> n >> q;
	for(int i = 1; i <= n; i++) 
		cin >> s[i] >> t[i];
}
string RP(string x, int pos, string _s){
	for(int i = pos; i < pos + _s.size(); i++)
		x[i] = _s[i - pos];
	return x;
}
void solve(){
	int ans = 0;
	
	for(int ygg = 1; ygg <= n; ygg++){
		if(s[ygg].size() > S.size()) continue;
		//dbg(s[ygg].size());
		for(int i = 0; i <= S.size() - s[ygg].size(); i++){
			int flag = 1;
			for(int j = 0; j < s[ygg].size(); j++){
				//dbg(i + j), dbg(j), dbg(S[i + j]), dbg(s[ygg][j]);
				if(S[i + j] != s[ygg][j]) {
					flag = 0;
					break;
				}
			}
			
			if(flag == 1){
				//dbg(S), dbg(i), dbg(s[ygg]), dbg(RP(S, i, s[ygg])), dbg(T);
				if(RP(S, i, t[ygg]) == T) ans++;
			}
		}
	}
	cout << ans << endl;
}
signed main(){
//	string x = "xabcx";int pos = 3;string  _s = "yue";
//	cout << RP(x, pos, _s);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	read();
	
	while(q--){
		cin >> S >> T;
		solve();
	}
	return 0;
}

