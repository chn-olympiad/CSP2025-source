#include<bits/stdc++.h>

using namespace std;

const int SIZN = 2e5 + 10;

int n,q;
pair<string,string> s[SIZN];
bool find(int pos,string s1,string s2) {
	int len2 = s2.length();
	for(int i = 0 ; i < len2 ; i++) {
		if(s1[pos + i] != s2[i])return false;
	}
	return true;
}
string cop(int pos,string s1,string s2) {
	int len2 = s2.length();
	for(int i = 0 ; i < len2 ; i++) {
		s1[pos + i] = s2[i];
	}
	return s1;
}
bool cmp(pair<string,string> s1,pair<string,string> s2) {
	s1.first.length() < s2.first.length();
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++) {
		cin >> s[i].first >> s[i].second;
	}
	for(int i = 1 ; i <= q ; i++) {
		int ans = 0;
		string st,en;
		cin >> st >> en;
		int l = 0,r = st.length() - 1;
		while(st[l] == en[l])l++;
		while(st[r] == en[r])r--;
		for(int j = 1 ; s[j].first.length() > l - r + 1 ; j++) {
			for(int pos = r - s[j].first.length() - 1 ; pos <= l ; pos++) {
				if(find(pos,st,s[j].first)) {
					if(cop(pos,st,s[j].second) == en)ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
