#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N = 105;
map<string, string> mp;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string x, y;
		cin >> x >> y;
		mp[x] = y;
	}
	while(q--){
		int ans = 0;
		string x, y;
		cin >> x >> y;
		for(int i = 0; i < x.size(); i++){
			for(int j = i + 1; j < x.size(); j++){
				if(mp.count(x.substr(i, j - i + 1))) continue;
				string s = x.substr(0, i) + x.substr(i, j - i + 1) + x.substr(j + 1, x.size() - j);
				if(s == y) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
