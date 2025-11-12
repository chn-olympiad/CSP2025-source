#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
unordered_map<string, string> mp;

bool try_re(string s, string s_, string key){
	if(s.size()!=s_.size()) return false;
	int id = 0;
	for(int i=0;i<s.size();++i){
		if(s[i]==key[id]){
			id++;
		} else {
			id=0;
		}
		if(id>=key.size()){
			string v = mp[key];
			for(int x=0;x<key.size();++x){
				s[i-id+x+1] = v[x];
			}
			if(s == s_) return true;
			else return false;
		} 
	}
	return false;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q, ans=0;
	cin >> n >> q;
	for(int i=1;i<=n;++i){
		string x, y;
		cin >> x >> y;
		mp[x] = y;
	}
	for(int i=1;i<=q;++i){
		string x, y;
		cin >> x >> y;
		for(auto [k, v]:mp){
			ans += try_re(x, y, k);
		}
		cout << ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
