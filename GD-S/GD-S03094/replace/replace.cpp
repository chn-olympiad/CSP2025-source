#include <bits/stdc++.h>
using namespace std;
string s[200005][3];
map<string, string> mp;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s[i][1] >> s[i][2];
		mp[s[i][1]] = s[i][2];
	}
	for(int i = 1; i <= q; i++){
		int ans = 0;
		string a, b;
		cin >> a >> b;
		if(a.length() != b.length()){
			cout << 0 << endl;
			continue;
		}
		int qm_end = -1, hm_start = -1;
		for(int j = 0; j < a.length(); j++){
			if(a[j] != b[j]){
				qm_end = j - 1; 
				break;
			}
		}
		for(int j = a.length() - 1; j >= 0; j--){
			if(a[j] != b[j]){
				hm_start = j + 1;
				break;
			}
		}
		for(int i = 0; i <= qm_end + 1; i++){
			for(int j = hm_start - 1; j < a.length(); j++){
				string y = "";
				string yp = "";
				for(int k = i; k <= j; k++){
					y += a[k];
					yp += b[k];
				}
				if(mp[y] == yp){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}
