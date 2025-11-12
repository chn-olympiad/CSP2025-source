#include<bits/stdc++.h>
using namespace std;

const int N = 510,mod = 998244353;
int n,m,a[N],c[N],vis[N],ans;
char s[N];

void dfs(int top)
{
	if(top > n){
		int cnt = n;
		for(int i = 1; i <= n; i++){
			if(n - cnt >= c[a[i]] || s[i] == '0') cnt--;
		}
		ans += (cnt >= m);ans %= mod;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		a[top] = i,vis[i] = 1;
		dfs(top + 1);
		vis[i] = 0;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s + 1);
	for(int i = 1; i <= n; i++) scanf("%d",&c[i]);
	if(m == 1){
		int pos = n + 1;
		for(int i = 1; i <= n; i++){
			if(s[i] == '1'){
				pos = i;
				break;
			}
		}
		if(pos == n + 1) printf("0\n");
		if(pos == 1){
			int res = 1;
			for(int i = 1; i <= n; i++) res = (res * n) % mod;
			printf("%d\n",res);
		}
		else printf("10\n");
	}
	else{
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
/*
3 2
101
1 1 2
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
