#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 998244353;

int n,m;
ll ans;
char s[511];
int c[511],t[511],vis[511];

void dfs(int x) {
	if (x == n + 1) {
		int sum = 0,res = n;
		for(int i=1;i<=n;i++) {
			if (sum >= c[t[i]] || s[i] == '0') {
				res--;
				sum++;
			}
		}
		if (res >= m)
			ans = (ans + 1) % mod;
		return ;
	}
	for(int i=1;i<=n;i++) {
		if (!vis[i]) {
			vis[i] = 1;
			t[x] = i;
			dfs(x + 1);
			vis[i] = 0;
			t[x] = 0; 
		}
	}
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s + 1);
	int flag = 1;
	for(int i=1;i<=n;i++) {
		scanf("%d",&c[i]);
		if (c[i] == 0)
			flag = 0;
		if (s[i] == '0')
			flag = 0;
	}
	if (m == n) {
		if (flag == 0) {
			puts("0");
		}
		else {
			ans = 1;
			for(int i=1;i<=n;i++)
				ans = ans * i % mod;
			printf("%lld",ans);
		}
		return 0;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
