#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 0x3f3f3f3f;
const ll Inf = 0x3f3f3f3f3f3f3f3f;
const int N = 5e5 + 5,M = (1 << 20) + 5;
int n,k,a[N],s[N],lst[M],f[N],maxx[N];

void solve() {
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++) {
		scanf("%d",&a[i]);
		s[i] = (s[i - 1] ^ a[i]);
	}
	maxx[n + 1] = 0;
	for(int i = n;i >= 1;i--) {
		lst[s[i]] = i;
		int x = (s[i - 1] ^ k);
		if(lst[x]) f[i] = maxx[lst[x] + 1] + 1;
		maxx[i] = max(maxx[i + 1],f[i]);
	}
	printf("%d",maxx[1]);
}

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int T = 1;
//	scanf("%d",&T);
	while(T--) solve();
	return 0;
}