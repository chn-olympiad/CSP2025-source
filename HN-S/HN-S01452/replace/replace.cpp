#include <bits/stdc++.h>
using namespace std;
#define int long long
int const N = 1e6 + 100;
bool check(string s){
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '0') return false;
	}
	return true;
}
int n, m;
string s;
int tr[N][1], t;
int cp[N], P[N], qz[N], hz[N];

int find(string s){
	int pos = 0;
	for(int i = 0; i < s.size(); i++){
		int x = s[i] - '0';
		if(!tr[pos][x]) return -1;
		pos = tr[pos][x];
	}
	return cp[pos];
}
int const B = 131;
int const M = 1e9 + 7; 
map<string, string> mp;
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	
	P[0] = 1; 
	for(int i = 1; i <= 1000000; i++) P[i] = P[i-1] * B % M; 
	
	for(int i = 1; i <= n; i++){
		string s1, s2;
		cin >> s1 >> s2;
		mp[s1] = s2;
	}
	
	while(q--){
		string s1, s2;
		cin >> s1 >> s2;
		int st = 0, ed = 0, ans = 0, f = 0;
		for(int i = 0 ; i < s1.size(); i++){
			//cout << i << " " << s1[i] << " " << s2[i] << endl;
			if(s1[i] != s2[i] && !f)  st = i, ed = i,f = 1;
			else if(s1[i] != s2[i]) ed = i;
		}
		string ss1 = "", ss2 = "";
		for(int i = st; i <= ed; i++){
			ss1 += s1[i];
			ss2 += s2[i];
		}
		for(int i = 0; i <= st; i++){
			for(int j = ed; j < s1.size(); j++){
				string q1 = "", q2 = "";
				for(int k = i; k <= j; k++){
					q1 += s1[k];
					q2 += s2[k];
				}
				if(mp[q1] == q2) ans++;
			}
		}
		
		cout << ans << "\n";
	}
	return 0;
}
