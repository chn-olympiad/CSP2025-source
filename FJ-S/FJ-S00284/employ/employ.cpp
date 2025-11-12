#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
char s[506];
int c[506];

int num[19], vis[19], ans;

void dfs(int x){
	if (x==n+1){
		int fail=0;
		for (int i=1; i<=n; i++)
			if (c[num[i]]<=fail || s[i]=='0')
				fail++;
		if (n-fail>=m)	ans++;
		return ;
	}
	
	for (int i=1; i<=n; i++)
		if (!vis[i]){
			vis[i]=1;
			num[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	scanf("%s", s+1);
	for (int i=1; i<=n; i++)	scanf("%d", &c[i]);
	
	dfs(1);
	printf("%d\n", ans);
	return 0;
}
