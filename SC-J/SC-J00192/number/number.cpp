#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
string s;
char ans[maxn + 5];
int len = 0;
bool comp(const char& x,const char& y) {
	return x > y;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0;i < (int)s.size();i ++) {
		char ch = s[i];
		if (ch >= '0' && ch <= '9') ans[++ len] = ch;
	}
	sort(ans + 1,ans + len + 1,comp);
	printf("%s",ans + 1);
	return 0;
}