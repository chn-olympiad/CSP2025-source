#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;

int n, m;
char s[maxn], a[maxn];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s); n = strlen(s);
	for (int i = 0; i < n; i++) if (isdigit(s[i])) a[m++] = s[i];
	sort(a, a+m, greater<char>());
	puts(a);
	return 0;
}
