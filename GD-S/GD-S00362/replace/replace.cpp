#include <iostream>
#include <map>
#define pss pair<string, string>
#define fs first
#define sc second
#define IO
using namespace std;
const int N = 2e5+5;
int n, q, cnt;
string t1, t2;
pss s[N];
map <string, string> mp;
map <string, int> vis;
bool comp(string s1, string s2){
	return (mp.find(s1) != mp.end() && mp[s1] == s2);
}
void dfs(string s1, string s2, int pos1, int pos2, int pos3){
	if (vis[s1]) return;
	vis[s1] = 1;
//	if (comp(s1, s2)){
//		cnt++;
//		cout << s1 << ' ' << s2 << '\n';
//	}
	cnt += comp(s1, s2);
	if (pos1 >= 1){
		s1 = t1[pos1-1]+s1;
		s2 = t2[pos1-1]+s2;
		pos1--;
		dfs(s1, s2, pos1, pos2, pos3);
	}
	if (pos2 < t1.length() && pos3 < t2.length()){
		s1 = s1+t1[pos2+1];
		s2 = s2+t2[pos3+1];
		pos2++, pos3++;
		dfs(s1, s2, pos1, pos2, pos3);
	}
}
int main(){
	#ifdef IO
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i){
		cin >> s[i].fs >> s[i].sc;
		mp[s[i].fs] = s[i].sc;
	}
	for (string n1, n2; q; --q){ // <=20pts
		cnt = 0;
		cin >> t1 >> t2;
		int pos1 = 0, pos2 = t1.length()-1, pos3 = t2.length()-1;
		for (; pos1 < min(t1.length(), t2.length()) && t1[pos1] == t2[pos1]; ++pos1);
		for (; pos2 >= 0 && pos3 >= 0 && t1[pos2] == t2[pos3]; --pos2, --pos3);
		n1 = "", n2 = "";
		for (int i = pos1; i <= pos2; ++i) n1 += t1[i];
		for (int i = pos1; i <= pos3; ++i) n2 += t2[i];
		// n1 -> n2
		dfs(n1, n2, pos1, pos2, pos3);
		vis.clear();
		cout << cnt << '\n';
	}
	
	return 0; 
}
/*
3 4
a b
b c
c d
acbdegh acbgedfh
aa b
a c
b a
*/
