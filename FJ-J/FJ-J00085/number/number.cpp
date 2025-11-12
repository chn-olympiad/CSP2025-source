#include <bits/stdc++.h>
using namespace std;
char a[1000009], b;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i=0;i<=sizeof(s);i++) {
		if (((s[i] - '0') <= 9) && ((s[i] - '0') >= 0)) {
			a[i] = s[i];		
		}
	}
	for (int i=9;i>=0;i--) {
		b=char(48+i);
		for (int j=0;j<=sizeof(s);j++) {
			if (a[j] == b) {
				cout << a[j];
			}
		}
	}
	return 0;
}
