#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> g;
	for(int i=0;i<(int)s.size();i++) 
		if('0'<=s[i]&&s[i]<='9') g.push_back(s[i]-'0');
	sort(g.begin(),g.end());
	reverse(g.begin(),g.end());
	for(int i=0;i<(int)g.size();i++) cout<<g[i];
} 
