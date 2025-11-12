#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
int a[N], s[N], l[N], r[N], dp[N];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, maxn = 0;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i ++){
		maxn = max(maxn, a[i]);
		scanf("%d", &a[i]);
		s[i] = s[i-1] ^ a[i];
	}
	if(maxn == 1){
		int ans = 0;
		if(k == 1){
			for(int i = 1; i <= n; i ++)
				ans += (a[i] == 1);
			printf("%d", ans);
		}
		else{
			for(int i = 1; i <= n; i ++)
				ans += (a[i] == 0);
			int cnt = 0;
			for(int i = 1; i <= n; i ++){
				if(a[i] == 1) cnt ++;
				else ans += cnt / 2, cnt = 0;
			}
			printf("%d", ans);
		}
		return 0;
	}
	memset(dp, -1, sizeof dp);
	for(int i = 1; i <= n; i ++){
		bool fl = 0;
		for(int j = i; j <= n; j ++)
			if((s[j] ^ s[i-1]) == k){
				l[i] = i, r[i] = j;
				//printf("%d %d %d\n", i, j, s[j] ^ s[i-1]);
				fl = 1;
				break;
			}
		if(fl == 0) l[i] = r[i] = -1;
	}
	int ans = 0;
	dp[1] = ((l[1] != -1) && (r[1] != -1));
	ans = max(ans, dp[1]);
	for(int i = 2; i <= n; i ++){
		if(l[i] == -1 && r[i] == -1){
			for(int j = 1; j <= i; j ++)
				dp[i] = max(dp[i], dp[j]);
			if(dp[i] == -1) dp[i] = 0;
			//printf("%d %d\n", dp[i], i);
			continue;
		}
		for(int j = i; j >= 1; j --)
			if(r[j] < l[i] && (r[j] != -1)){
				dp[i] = max(dp[i], dp[j]+1);
			}
		if(dp[i] == -1) dp[i] = 1;
		ans = max(ans, dp[i]);
		//printf("%d %d\n", dp[i], i);
	}
	printf("%d", ans);
	return 0;
}
