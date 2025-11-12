#include <bits/stdc++.h>
using namespace std;
string s;
int j;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i ++)
		if (s[i] <= '9' && s[i] >= 0)a[++j] = s[i]-'0';
	sort(a+1,a+j+1);
	for (int i = j; i >= 1; i --)cout << a[i];
	return 0;
}
