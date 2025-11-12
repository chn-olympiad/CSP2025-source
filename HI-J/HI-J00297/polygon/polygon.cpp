#include <iostream>
#include <cstdio>
using namespace std;

bool flag[5010];
int n,ans,lim,a[5010];

void dfs(int step,int pos,int sum,int maxn) {
	if (step >= lim) {
		if (sum > maxn * 2) ans = (ans+1) % 998244353;
		return;
	}
	flag[pos] = true;
	for (int i = pos;i <= n;i++) {
		if (!flag[i]) {
			dfs(step+1,i,sum+a[i],max(maxn,a[i]));
		}
	}
	flag[pos] = false;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int i = 3;i <= n;i++) {
		lim = i;
		dfs(0,0,0,0);
	}
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
}
