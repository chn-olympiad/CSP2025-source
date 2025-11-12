#include<bits/stdc++.h>
using namespace std;
string s;int a[1000010], cnt;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	for(int i = 0; i < s.length(); i++) {
		if(s[i] <= '9' && s[i] >= '0'){
			a[++cnt] = s[i] - '0';
		}
	} 
	sort(a + 1, a + cnt + 1, greater<int>());
	for(int i = 1; i <= cnt; i++) printf("%d", a[i]);
	return 0;
}

