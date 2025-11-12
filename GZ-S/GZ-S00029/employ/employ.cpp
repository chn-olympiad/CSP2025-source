//GZ-S00029 遵义市第十九中学 余学森 
#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int MOD = 998244353;
char s[N];
bool vis[N],give_up[N];
int n, m, c[N], t[N], sum = 0;
unsigned long long ans = 0;

void dfs(int now,int tot){
	if (now > n) {
		int used = 0;
	    for(int i = 1; i <= n; i++){
	    	used+=!(give_up[now]);
		}
		if(used>=m){
			ans++;
			ans-=(ans>=MOD?MOD:0);
		}
	}
	if (tot>=c[now]||!s[now]){
		tot++;
		give_up[now]=1;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue ;
		vis[i] = 1;
		dfs(i, tot);
		vis[i] = 0;
	}
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		sum += (s[i] - '0');
		vis[i] = 0;
		give_up[i]=0;
	}
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (sum == n) {
		unsigned long long res = n;
		for (unsigned long long i = n - 1; i >= 2; i--)
		    res = (res * i) % MOD;
		cout << res;
	} else {
		dfs(1, 0);
		cout <<ans;
	}
	return 0;
}
