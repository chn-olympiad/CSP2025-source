#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t;
int n;
int x[maxn][4];
int cnt[3];
long long ans = -1;
void dfs(long long ge,long long sum) {
	if(ge == n + 1) {
		ans = max(ans,sum);
		return;
	}
	for(int i = 1;i <= 3;i++) {
		if(cnt[i] + 1 <= n / 2) {
			cnt[i]++;
			sum += x[ge][i];
			dfs(ge + 1,sum);
			cnt[i]--;
			sum -= x[ge][i];
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		ans = -1;
		for(int i = 1;i <= n;i++) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			x[i][1] = a;
			x[i][2] = b;
			x[i][3] = c;
		}
		for(int i = 1;i <= 3;i++) {
			memset(cnt,0,sizeof(cnt));
			cnt[i]++;
			dfs(2,x[1][i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
