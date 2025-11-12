#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000005],pos;

int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	for (int i = 0;i < s.size();i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			a[pos] = s[i] - '0';
			pos++;
		}
	}
	pos--;
	sort(a,a + pos + 1);
	for (int i = pos;i >= 0;i--) {
		cout << a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
