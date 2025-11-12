#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 0x3f3f3f3f;
const ll Inf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 5,M = 15;
int n,c[M];
char s[N];

void solve() {
	scanf("%s",s + 1);
	n = strlen(s + 1);
	for(int i = 1;i <= n;i++) 
		if(s[i] >= '0' && s[i] <= '9')
			c[s[i] - '0']++;
	for(int i = 9;i >= 0;i--)
		while(c[i]--) printf("%d",i);
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T = 1;
//	scanf("%d",&T);
	while(T--) solve();
	return 0;
}