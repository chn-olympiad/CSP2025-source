#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int a[1000005],t;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	s = ' ' + s;
	int len = s.size();
	for (int i = 1; i <= len; i++)
		if (s[i] >= '0' && s[i] <= '9')
			a[++t] = s[i] - '0';
	sort (a + 1,a + t + 1);
	for (int i = t; i >= 1; i--) printf("%d",a[i]);
	return 0;
}
