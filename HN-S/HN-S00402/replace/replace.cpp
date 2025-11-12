#include <bits/stdc++.h>
using namespace std;

typedef pair<string, string> PII;

int n, q;
string s1, s2, t1, t2;
map<string, string> re;
map<PII, int> in;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	scanf("%d %d", &n, &q);
	while(n --) {
		cin >> s1 >> s2;
		int l = -1, r = -1, m = s1.size();
		for(int i = 0; i < m; i ++)
			if(s1[i] != s2[i]) {l = i; break;}
		for(int i = m - 1; i >= 0; i --)
			if(s1[i] !=  s2[i]) {r = i; break;}
			
		if(s1 != s2) {
			string diff1 = s1.substr(l, r - l + 1), diff2 = s2.substr(l, r - l + 1);
			re[diff1] = diff2;
			in[{diff1, diff2}] ++;
		}  
	}
	while(q --) {
		cin >> t1 >> t2;
		int l = 0, r = 0, m1 = t1.size(), m2 = t2.size();
		for(int i = 0; i < m1; i ++) 
			if(t1[i] != t2[i]) {l = i; break;}
			
		for(int i = m1 - 1; i >= 0; i --) 
			if(t1[i] != t2[i + m2 - m1]) {r = i; break;}
		
		string diff1 = t1.substr(l, r - l + 1), diff2 = t2.substr(l, r + m2 - m1 - l + 1);
		cout << in[{diff1, diff2}] << endl;
	}
}
