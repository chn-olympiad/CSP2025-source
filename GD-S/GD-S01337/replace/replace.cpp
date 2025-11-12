#include<bits/stdc++.h>
using namespace std;
vector<int> prefix_function(string s) {
	vector<int> pi(s.size());
	for(int i = 0, j = 0; i < (int)s.size(); i++) {
		for(; j > 0 && s[j] != s[i]; j = pi[j]);
		if(s[j] == s[i]) j++;
		pi[i] = j;
	}
	return pi;
}
int kmp(string s1, string s2, string t1, string t2) {
	int len1 = s1.size(), len2 = t1.size();
	string a = t1 + t2, b = a;
	reverse(b.begin(), b.end());
	vector<int> pi1 = prefix_function(s1 + '#' + t1), pi2 = prefix_function(s2 + "#" + t2), pi3 = prefix_function(a), pi4 = prefix_function(b);
	for(int i = len1 + 1; i <= len1 + len2; i++) {
		if(pi1[i] == len1 && pi2[i] == len2) {
			int l = i - 2 * len1 - 1, r = i + 1; bool flag1 = 0, flag2 = 0;
			for(int j = pi3[l + len2]; j > 0; j = pi3[j]) 
				if(j == l)
					flag1 = 1;
			for(int j = pi4[2 * len2 - r]; j > 0; j = pi4[j])
				if(j == l)
					flag2 = 1;
			if(flag1 && flag2) return 1;
		}
	}
	return 0;
}
string s1[200010], s2[200010];
int main(){
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	int n, q, cnt = 0;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1[i] >> s2[i];
	}
	for(int i = 1; i <= q; i++) {
		string t1, t2;
		cin >> t1 >> t2;
		for(int j = 1; j <= n; j++)
			cnt += kmp(s1[j], s2[j], t1, t2);	
	}
	cout << cnt;
	return 0;
}

