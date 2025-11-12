#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 4e3 + 7;
int t;
int n;
int a[100007][3];
ll f[N][N];
ll f2[100007];
ll ans;
vector<int>g;
void dfs(int now, int c1, int c2, int c3, ll sum){
	if(now > n){
		ans = max(ans, sum);
		return;
	}
	if(c1 + 1 <= n / 2){
		dfs(now + 1, c1 + 1, c2, c3, sum + a[now][0]);	
	}
	if(c2 + 1 <= n / 2){
		dfs(now + 1, c1, c2 + 1, c3, sum + a[now][1]);
	}
	if(c3 + 1 <= n / 2){
		dfs(now + 1, c1, c2, c3 + 1, sum + a[now][2]);
	}
}
void init(){
	memset(f, 0, sizeof(f));
	memset(f2, 0, sizeof(f2));
	ans = 0;
}
bool cmp1(int x, int y){
	return x > y;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		init();
		bool flg1 = 0, flg2 = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
			flg1 |= a[i][1];
			flg2 |= a[i][2];
		}
		if(n <= 10){
			dfs(1, 0, 0, 0, 0);
			printf("%lld\n", ans);
			continue;
		}
		if(n <= 200 || flg2){
			for(int i = 1; i <= n; i++){
				for(int j = min(i, n / 2); j >= 0; j--){
					for(int k = min(i - j, n / 2); k >= 0; k--){
						int l = i - j - k;
						if(l > n / 2) continue;
						if(j){
							f[j][k] = max(f[j][k], f[j - 1][k] + a[i][0]);
						}
						if(k){
							f[j][k] = max(f[j][k], f[j][k - 1] + a[i][1]);
						}
						if(l){
							f[j][k] = max(f[j][k], f[j][k] + a[i][2]);
						}
						if(i == n) ans = max(ans, f[j][k]);
					}
				}
			}
			printf("%lld\n", ans);
			continue;
		}
		if(!flg1){
			if(g.size()) g.clear();
			for(int i = 1; i <= n; i++) g.push_back(a[i][0]);
			sort(g.begin(), g.end(), cmp1);
			for(int i = 1; i <= n / 2; i++){
				ans += g[i - 1];
			}
			printf("%lld\n", ans);
			continue;
		}
		if(!flg2){
			for(int i = 1; i <= n; i++){
				for(int j = min(i, n / 2); j >= 0; j--){
					int k = i - j;
					if(j) f2[j] = max(f2[j], f2[j - 1] + a[i][0]);
					if(k) f2[j] = max(f2[j], f2[j] + a[i][1]); 
					if(i == n) ans = max(ans, f2[j]);
				}
			}
			printf("%lld\n", ans);
			continue;
		}
	}
	return 0;
} 
// very despair!!!  ovo
