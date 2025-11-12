#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int s[N][3];
int n, h;
int dfs(int sel, int one, int two, int thr, int tot) {
//	printf("dfs(%d, {%d,%d,%d}, %d)\n",sel,one,two,thr,tot);
	if (one > h || two > h || thr > h) {
		return 0;
	}
	if (sel > n) {
		return tot;
	}
	return max({
		dfs(sel+1, one+1, two, thr, tot + s[sel][0]),
		dfs(sel+1, one, two+1, thr, tot + s[sel][1]),
		dfs(sel+1, one, two, thr+1, tot + s[sel][2])
	});
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		h = n>>1;
		for (int i=1;i<=n;i++) {
			scanf("%d%d%d",	&s[i][0],
							&s[i][1],
							&s[i][2]);
		}
		printf("%d\n",dfs(1,0,0,0,0));
	}
	
	return 0;
}
