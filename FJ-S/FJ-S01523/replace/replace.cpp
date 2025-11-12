#include<bits/stdc++.h>
using namespace std;
typedef pair<string, string> rp;
typedef pair<int, string> conf;
map<rp, vector<conf>> mp;
int n, q; vector<conf> tmp;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string s1, s2; cin >> s1 >> s2;
		string x1 = "", x2 = "", cf = ""; int cnt = 0, ladd = 0; bool flag = 1;
		for(int j = 0; j < s1.size(); j++)
			if(s1[j] == s2[j]) cf += s1[j], flag? cnt++ : (x1 += '\0', x2 += '\0', 0);
			else x1 += s1[j], x2 += s2[j], flag = 0, cf += '\0', ladd = x1.size();
		x1 = x1.substr(0, ladd), x2 = x2.substr(0, ladd);
		mp[make_pair(x1, x2)].push_back({cnt, cf});
	}
	while(q--){
		string s1, s2; cin >> s1 >> s2;
		string x1 = "", x2 = "", cf = ""; int cnt = 0, ladd = 0; bool flag = 1;
		for(int j = 0; j < s1.size(); j++)
			if(s1[j] == s2[j]) cf += s1[j], flag? cnt++ : (x1 += '\0', x2 += '\0', 0);
			else x1 += s1[j], x2 += s2[j], flag = 0, cf += '\0', ladd = x1.size();
		x1 = x1.substr(0, ladd), x2 = x2.substr(0, ladd);
		if(!mp.count(make_pair(x1, x2))){
			puts("0"); continue;
		}
		tmp = mp[make_pair(x1, x2)]; int ans = 0;
		for(conf str: tmp){
			if(str.first > cnt) continue;
			int stpos = cnt - str.first;
			string k = str.second;
			for(int i = 0; i < k.size(); i++)
				if(k[i] != cf[stpos + i]) goto end;
			ans++; end:;
		}
		printf("%d\n", ans);
	}
	return 0;
}

