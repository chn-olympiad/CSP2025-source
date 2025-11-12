#include<bits/stdc++.h>
#define itn int
#define pii pair<int,int>
#define el cout<<"\n"
#define fi first
#define se second
//#define int long long
using namespace std;
int cnt[20];
char c;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while (c = getchar(), c != EOF)
		if ('0' <= c && c <= '9')cnt[c - '0']++;
	for (int i = 9; ~i; i--)
		while (cnt[i]--)
			cout << i;
	return 0;
}