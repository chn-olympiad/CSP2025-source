//GZ-S00233 盘州市第二中学 李泽鑫 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int T;
int n;
struct sb{
	int a, b, c;
}x[N];
int a1[N];
ll res[N], cnt = 0;
int na = 0, nb = 0, nc = 0;
ll now = 0;
void dfs(int id){
	if(id == n + 1){
		res[ ++ cnt] = now;
		return;
	}
	for(int i = 1; i <= 3; i ++ ){
		if(na < (n / 2)){
			na ++ ;
			now += x[id].a;
			dfs(id + 1);
			now -= x[id].a;
			na -- ;
		}
		if(nb < (n / 2)){
			nb ++ ;
			now += x[id].b;
			dfs(id + 1);
			now -= x[id].b;
			nb -- ;
		}
		if(nc < (n / 2)){
			nc ++;
			now += x[id].c;
			dfs(id + 1);
			now -= x[id].c;
			nc -- ;
		}
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T -- ){
		now = 0;
		na = nb = nc = 0;
		cnt = 0;
		ll ans = 0;
		bool flag = true;
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++ ){
			scanf("%d%d%d", &x[i].a, &x[i].b, &x[i].c);
			if(x[i].c != 0 || x[i].b != 0)flag = false;
		}
		if(flag){
			for(int i = 1; i <= n; i ++ ){
				a1[i] = x[i].a;
			}
			sort(a1 + 1, a1 + n + 1);
			for(int i = n; i > n / 2; i -- ){
				ans += a1[i]; 
			} 
			printf("%lld\n", ans);
		}
		else{
			ans = -1;
			dfs(1);
			for(int i = 1; i <= cnt; i ++ ){
				ans = max(ans, res[i]);
			} 
			printf("%lld\n", ans);
		}
	}
	return 0;
}
