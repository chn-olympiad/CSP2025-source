#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
vector<int> m;
bool cmp(int a,int b) {
	return a > b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < (int)s.size();i++) {
		if('0' <= s[i]&&s[i] <= '9') {
			m.push_back(s[i]-'0');
			cnt++;
		}
	}
	sort(m.begin(),m.end(),cmp);
	for(int i = 0;i < (int)m.size();i++) cout << m[i];
	return 0;
}
