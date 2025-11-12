#include <bits/stdc++.h>
#define LL long long
#define PII pair <LL, LL>
using namespace std;
const LL N = 2e5 + 5, P = 1e9 + 3;
LL n, m, slen;
LL p31[N], h1[N][2], h2[N][2];
string str1[N][2], str2[N][2];
vector <PII> v[(LL)1e7+5];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	p31[0] = 1;
	for(LL i = 1; i < N; i ++ ) p31[i] = p31[i - 1] * 31 % P;
	cin >> n >> m;
	for(LL i = 1; i <= n; i ++ ) {
		cin >> str1[i][0] >> str1[i][1];
		slen += str1[i][0].size() + str1[i][1].size();
	}
	for(LL i = 1; i <= m; i ++ ) {
		cin >> str2[i][0] >> str2[i][1];
		slen += str2[i][0].size() + str2[i][1].size();
	}
	if(slen > 1e4) {
		for(LL i = 1; i <= n; i ++ ) {
			if(str1[i][0].size() != str1[i][1].size()) continue;
			LL len = str1[i][0].size();
			str1[i][0] = ' ' + str1[i][0];
			str1[i][1] = ' ' + str1[i][1];
			LL pos1, pos2;
			for(LL j = 1; j <= len; j ++ ) if(str1[i][0][j] == 'b') pos1 = j;
			for(LL j = 1; j <= len; j ++ ) if(str1[i][1][j] == 'b') pos2 = j;
			v[pos1 - pos2+(LL)5e6].push_back({pos1, len - pos1});
		}
		for(LL i = 1; i <= m; i ++ ) {
			if(str2[i][0].size() != str2[i][1].size()) continue;
			LL len = str2[i][0].size(), cnt = 0;
			str2[i][0] = ' ' + str2[i][0];
			str2[i][1] = ' ' + str2[i][1];
			LL pos1, pos2;
			for(LL j = 1; j <= len; j ++ ) if(str2[i][0][j] == 'b') pos1 = j;
			for(LL j = 1; j <= len; j ++ ) if(str2[i][1][j] == 'b') pos2 = j;
			for(PII j:v[pos1-pos2+(LL)5e6]){
				if(j.first<=pos1 && j.second<=len-pos1)cnt++;
			}
			cout<<cnt<<'\n';
		}
		return 0;
	}
	for(LL i = 1; i <= n; i ++ ) {
		if(str1[i][0].size() != str1[i][1].size()) continue;
		LL len = str1[i][0].size();
		str1[i][0] = ' ' + str1[i][0];
		str1[i][1] = ' ' + str1[i][1];
		for(LL j = 1; j <= len; j ++ ) {
			h1[i][0] = (h1[i][0] * 31 + str1[i][0][j] - 'a') % P;
			h1[i][1] = (h1[i][1] * 31 + str1[i][1][j] - 'a') % P;
		}
	}
	for(LL i = 1; i <= m; i ++ ) {
		if(str2[i][0].size() != str2[i][1].size()) {
			cout << 0 << '\n';
			continue;
		}
		LL len = str2[i][0].size(), cnt = 0;
		str2[i][0] = ' ' + str2[i][0];
		str2[i][1] = ' ' + str2[i][1];
		LL pos = len;
		while(pos && str2[i][0][pos] == str2[i][1][pos]) pos -- ;
		for(LL j = 1; j <= len; j ++ ) {
			h2[j][0] = (h2[j - 1][0] * 31 + str2[i][0][j] - 'a') % P;
			h2[j][1] = (h2[j - 1][1] * 31 + str2[i][1][j] - 'a') % P;
			if(j >= pos) {
				for(LL k = 1; k <= n; k ++ ) {
					LL len_ = str1[k][0].size() - 1;
					if(len_ <= len && h2[j][0] - h2[j - len_][0] * p31[len_] == h1[k][0]
					 && h2[j - len_][0] * p31[len_] + h1[k][1] == h2[j][1])
						cnt ++ ;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
//long long

