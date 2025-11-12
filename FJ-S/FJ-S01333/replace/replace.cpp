#include <bits/stdc++.h>
#define int long long
constexpr int N = 1e6 + 5;
using namespace std;
int n,q,tot=0,ans = 0;
map<string,int>mp;
vector<string>e[N];
void work(string s,string t,int l,int r){
	string p;
	for(int i = l ; i <= r; i ++){
		p += s[i];
	}
	int tp = mp[p];
	if(!tp) return;
	for(auto k : e[tp]){
		string s2 = "#";
		for(int i = 1 ; i < l ; i ++) s2 += s[i];
		s2 += k;
		for(int i = r + 1 ; i < s.size();i ++) s2 += s[i];
		if(s2.size() != t.size()) continue;
		bool f = 1;
		for(int i = 1 ; i < s2.size() ; i ++){
			if(s2[i] != t[i]){
				f = 0;
				break;
			}
		} 
		if(f) ans += 1; 
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++){
		string s,t;
		cin >> s >> t;
		if(!mp[s]){
			mp[s] = ++tot;
		} 
		e[tot].push_back(t);
	}
	for(int i = 1 ; i <= q ; i ++){
		ans = 0;
		string s,t;
		cin >> s >> t;
		int l = s.size() , r = t.size();
		s = "#" + s;
		t = "#" + t; 
		for(int i = 1 ; i <= l ; i ++){
			for(int j = 1 ; j <= r ; j ++){
				work(s , t , i , j);
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 

