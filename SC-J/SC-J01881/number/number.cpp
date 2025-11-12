#include <bits/stdc++.h>
using namespace std;
#define cst const
#define sttc static
#define  FOR(i, s, e) for (int i=int(s);i<=int(e);i++)
#define _FOR(i, s, e) for (int i=int(s);i>=int(e);i--)

string s;
vector<char> ans;
inline bool is_num(cst char &c){return '0'<=c && c<='9';}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	
	cin>>s, ans.reserve(s.size());
	for (cst auto &c:s)if (is_num(c))ans.push_back(c);
	sort(ans.begin(), ans.end(), [&](cst char &a, cst char &b){return a>b;});
	for (cst auto &c:ans)putchar(c);
	return 0;
}