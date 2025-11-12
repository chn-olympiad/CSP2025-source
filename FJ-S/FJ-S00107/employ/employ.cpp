#include <bits/stdc++.h>
using namespace std;
int a[2000];
char s[2000];
bool v[2000];
int n,m;
int c[2000];long long ans = 0;
void dfs(int i){
	if(i == n + 1){
		int o = 0;
		for(int j = 1;j <= n;j++){
			if(!s[j] || o >= c[a[j]]) o++;
		}
		ans += (n - o >= m);
	}
	for(int j = 1;j <= n;j++){
		if(v[j]) continue;
		a[i] = j;
		v[j] = true;
		dfs(i + 1);
		v[j] = false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s + 1);
	for(int i = 1;i <= n;i++) s[i] ^= '0',scanf("%d",c + i);
	dfs(1);
	printf("%lld",ans % 998244353);
	return 0;
} 
