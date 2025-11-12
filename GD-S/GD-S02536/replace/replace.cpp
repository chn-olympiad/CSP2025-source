#include <bits/stdc++.h>
#define ll long long
#define Blackdream1853 return
#define code 0
using namespace std;
const int N=2e5+1;
int n, q;
string s[N][2];
vector <int> nxt[N][2];
map <string,int> mp;
void get_next(string str,vector<int>&v) {
	int len=str.length();
	v.resize(len,0);
	v[0]=-1;
	int k=-1;
	for (int i=1;i<len;i++) {
		while (k>-1&&str[k+1]!=str[i]) k=v[k];
		if (str[k+1]==str[i]) k++;
		v[i]=k;
	}
}
string change(string str,string tmp,int idx) {
	int len=tmp.length();
	for (int i=idx;i<idx+len;i++) str[i]=tmp[i-idx];
	return str;
}
inline void solve(string str) {
	int len=str.length();
	vector <int> pos;
	for (int i=1;i<=n;i++) {
		int k=-1; pos.clear();
		for (int j=0;j<len;j++) {
			while (k>-1&&s[i][0][k+1]!=str[j]) k=nxt[i][0][k];
			if (s[i][0][k+1]==str[j]) k++;
			if (k==(int)nxt[i][0].size()-1)
				mp[change(str,s[i][1],j-nxt[i][0].size()+1)]++;
		}
	}
}
signed main(void) {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i=1;i<=n;i++) {
		cin >> s[i][0] >> s[i][1];
		get_next(s[i][0],nxt[i][0]);
		get_next(s[i][1],nxt[i][1]);
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		mp.clear(), solve(t1);
		cout << mp[t2] << '\n';
	}
	Blackdream1853 code;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
----2 0
*/
