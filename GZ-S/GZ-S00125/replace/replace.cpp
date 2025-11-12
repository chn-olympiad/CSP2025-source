//GZ-S00125 贵阳市南明区李端棻中学 姜铭灿 
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
const int MAXN = 2e5 + 5; 
int n, q;
map <pair<string, string>, int> mp;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	string s1, s2;
	for(int i = 1; i <= n; i++) cin >> s1 >> s2, mp[{s1, s2}]++;
	while(q--){
		long long ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		if(t1.size() != t2.size()){
			cout << 0 << "\n";
			continue;
		}
		for(int l = 0; l < t1.size(); l++)
			for(int r = l; r < t1.size(); r++){
				string x = t1.substr(0, l), y = t1.substr(l, r - l + 1), z = t1.substr(r + 1);
				string u = t2.substr(0, l), v = t2.substr(l, r - l + 1), w = t2.substr(r + 1);
				if(x == u && z == w) ans += mp[{y, v}];
			}
		cout << ans << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
