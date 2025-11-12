#include <bits/stdc++.h>
using namespace std;

const int mod1 = 9999971, mod2 = 9999973;
const int base1 = 101, base2 = 137;
int n, q;
char t0[5000010], t1[5000010];
map<array<int, 4>, int> mp;

int main(){
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	scanf ("%d%d", &n, &q);
	int sa = 0;
	for (int i = 1; i <= n; i++){
		scanf ("%s%s", t0 + 1, t1 + 1);
		int len = strlen(t0 + 1);
		int l = 1, r = len;
		for (; l <= len && t0[l] == t1[l]; l++);
		for (; r && t0[r] == t1[r]; r--);
		if (l > r)
			continue;
		cout <<l << " " << r<<"\n";
		int ha0 = 0, hb0 = 0, ha1 = 0, hb1 = 0;
		for (int j = 1; j <= r - l + 1; j++)
			ha0 = (ha0 * base1 % mod1 + (t0[l + j - 1] - 'a')) % mod1;
		for (int j = 1; j <= r - l + 1; j++)
			hb0 = (hb0 * base2 % mod2 + (t0[l + j - 1] - 'a')) % mod2;
		for (int j = 1; j <= r - l + 1; j++)
			ha1 = (ha1 * base1 % mod1 + (t1[l + j - 1] - 'a')) % mod1;
		for (int j = 1; j <= r - l + 1; j++)
			hb1 = (hb1 * base2 % mod2 + (t1[l + j - 1] - 'a')) % mod2;
		++mp[{ha0, hb0, ha1, hb1}];
	}
	for (; q--; ){
		scanf ("%s%s", t0 + 1, t1 + 1);
		int len1 = strlen(t0 + 1), len2 = strlen(t1 + 1);
		if (len1 != len2){
			printf ("0\n");
			continue;
		}
		int l = 1, r = len1;
		for (; l <= len1 && t0[l] == t1[l]; l++);
		for (; r && t0[r] == t1[r]; r--);
		cout <<l << " " << r<<"\n";
		int ha0 = 0, hb0 = 0, ha1 = 0, hb1 = 0;
		for (int j = 1; j <= r - l + 1; j++)
			ha0 = (ha0 * base1 % mod1 + (t0[l + j - 1] - 'a')) % mod1;
		for (int j = 1; j <= r - l + 1; j++)
			hb0 = (hb0 * base2 % mod2 + (t0[l + j - 1] - 'a')) % mod2;
		for (int j = 1; j <= r - l + 1; j++)
			ha1 = (ha1 * base1 % mod1 + (t1[l + j - 1] - 'a')) % mod1;
		for (int j = 1; j <= r - l + 1; j++)
			hb1 = (hb1 * base2 % mod2 + (t1[l + j - 1] - 'a')) % mod2;
		printf ("%d\n", mp[{ha0, hb0, ha1, hb1}]);
	}
	return 0;
}

