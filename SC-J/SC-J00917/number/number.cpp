#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010],wz;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> s;
	for(int i = 0; i < s.size(); ++i)
		if(isdigit(s[i]))a[++wz] = s[i] - '0';
	sort(a + 1,a + wz + 1,greater<int>());
	for(int i = 1; i <= wz; ++i)cout << a[i];
	return 0;
}