#include <bits/stdc++.h>
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	freopen("replace.in", "r", stdin);
	//freopen("replace.out", "w", stdout);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	vector<vector<int>> nxts(n + 1);
	
	vector<pair<string, string>>S(n + 1);
	for(int I{1};I<=n;I++){
		string s1, s2;
		cin >> s1 >> s2;
		nxts[I] = vector<int>(s1.size() + 1);
		S[I] = (make_pair(s1, s2));
		int j{};
		for(int i{1};i<s1.size();i++){
			while(j > 0 && s1[j] != s1[i])j = nxts[I][j - 1];
			if(s1[j] == s1[i])j++;
			nxts[I][i] = j;
		}
	}
	while(q--){
		string t1, t2;
		cin >> t1 >> t2;
		int ans{};
		for(int I{1};I<=n;I++){
			cout << "I:" << I << '\n';
			if(t1.size() < S[I].first.size())continue;
			int j{};
			for(int i{};i<t1.size();i++){
				while(j > 0 && S[I].first[j] != t1[i])j = nxts[I][j - 1];
				if(S[I].first[j] == t1[i])j++;
				if(j == S[I].first.size()){
					string res = t1.substr(0, i - j + 1) + S[I].second + t1.substr(i + 1);
					if(res == t2)ans++;
					j = nxts[I][j - 1];
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
