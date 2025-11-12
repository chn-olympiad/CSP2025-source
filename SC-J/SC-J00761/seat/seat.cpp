#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 0x3f3f3f3f;
const ll Inf = 0x3f3f3f3f3f3f3f3f;
const int N = 15;
int n,m,a[N * N];

void solve() {
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n * m;i++) scanf("%d",&a[i]);
	int t = a[1];
	sort(a + 1,a + n * m + 1,greater <int>());
	int idx = 0;
	for(int i = 1;idx == 0 && i <= n * m;i++) if(t == a[i]) idx = i;
	idx--;
	int x = 1,y = 1;
	while(idx--) {
		if(y % 2) {
			x++;
			if(x > n) x = n,y++;
		}
		else {
			x--;
			if(x == 0) x = 1,y++;
		}
	}
	printf("%d %d",y,x);
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int T = 1;
//	scanf("%d",&T);
	while(T--) solve();
	return 0;
}