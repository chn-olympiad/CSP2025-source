#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n,q;
string s[N][5],a,b;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> s[i][1] >> s[i][2];
	}
	while (q--){
		cin >> a >> b;
		if (a.size() != b.size()){
			cout << 0 << '\n';
			continue;
		}
		int ans = 0;
		int len = a.size();
		int R = 0;
		for (int i = len - 1; i >= 0; i--)
			if (a[i] != b[i]){
				R = i + 1;
				break;
			}
		for (int i = 1; i <= n; i++){
			if (s[i][1] == a && s[i][2] == b) ans++;
			else{
				int k = s[i][1].size();
				for (int j = 0; j + k - 1 < len; j++){
					if (j && a[j - 1] != b[j - 1]) break;
					if (a.substr(j,k) == s[i][1]){
						if (b.substr(j,k) == s[i][2]){
							if (j + k < len){
						    	if(j + k >= R) ans++;
							}
							else ans++;
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
