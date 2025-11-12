#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
vector<int> a;
bool cmp(int x,int y) {
	return x > y;
}
signed main() {
	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(int i = 0; i < s.length(); i++) if(isdigit(s[i])) a.push_back(signed(s[i]-'0'));
	sort(a.begin(),a.end(),cmp);
	for(int i = 0; i < a.size(); i++) cout<<a[i];
	return 0;
}
