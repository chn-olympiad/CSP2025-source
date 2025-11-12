#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int l[qwe], z;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	scanf("%s", &s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			l[z] = s[i] - '0';
			z++;
		}
	}
	sort(l, l + z);
	for (int i = z - 1; i >= 0; i--)
		printf("%d", l[i]);
	return 0;
}