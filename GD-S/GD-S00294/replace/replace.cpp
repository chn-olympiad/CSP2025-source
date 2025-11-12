#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;

string s1[N], s2[N];
vector<int> nxt[N];
string T;

inline void calc(int p){
	int n = s1[p].size();
	nxt[p][0] = 0;
	int j = 0;
	for(int i = 2;i < n;i ++){
		while(j && s1[j + 1] != s1[i])  j = nxt[p][j];
		if(s1[j + 1] == s1[i]) ++j;
		nxt[p][i] = j;
	}
//	for(int i = 1;i < n;i ++)
//		cout << nxt[p][i] << " ";
//	cout << "\n";
}

int ans = 0, n;
inline void dfs(string S){
//	cout << S << "\n";
	int m = S.size() - 1;
	string s = S;
	for(int i = 1;i <= n;i ++){
		int j = 0, l = s1[i].size() - 1;
		for(int k = 1;k <= m;k ++){
			while(j && s1[i][j + 1] != S[k]) j = nxt[i][j];
			if(s1[i][j + 1] == S[k]) ++j;
			if(j == l){
				for(int z = k - l + 1, t = 1;z <= k;z ++)
					S[z] = s2[i][t++];
				if(S == T) ans++;
				S = s;
				j = nxt[i][j];
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int q;
	cin >> n >> q;
	for(int i = 1;i <= n;i ++){
		cin >> s1[i] >> s2[i];
		s1[i] = "!" + s1[i], s2[i] = "!" + s2[i];
		nxt[i].resize(s1[i].size() + 1);
		calc(i);
	}
	while(q--){
		string S;
		cin >> S >> T;
		S = "!" + S, T = "!" + T;
		if(S.size() != T.size()){
			cout << "0\n";
			continue ;
		}
		dfs(S);
		cout << ans << "\n";
		ans = 0;
	}
	return 0;
}
