#include<bits/stdc++.h>
using namespace std;
int n, q;
string s[1010], t[1010];
int main(){
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) cin >> s[i] >> t[i];
	while(q --){
		string a, b;
		cin >> a >> b;
		int cnt = 0;
		for(int i = 1; i <= n; i ++){
			bool ans = false;
			for(int st = 0; st < a.size() + 1 - s[i].size(); st ++){
				bool ok = true;
				for(int j = 0; j < s[i].size(); j ++){
					if(s[i][j] != a[st + j]){ ok = false; break; }
					if(t[i][j] != b[st + j]){ ok = false; break; }
				}
				if(ok){ ans = true; break; }
			}
			cnt += ans;
		}
		cout << cnt << endl;
	}
}