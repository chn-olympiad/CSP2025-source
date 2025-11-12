#include<bits/stdc++.h>
#define int long long
using namespace std;
bool flag = true;
int n , m , k , cnt , res = 1e17;
int a[15][10005] , c[15] , fa[10005] , mark[10005];
struct node{
	int u , v , w;
} p[10000005] , q[10000005];
bool cmp(node x , node y){
	return x.w < y.w;
}
int find(int x){
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}
void dfs(int x){
	if(x > k){
		int ans = 0;
		cnt = m;
		for(int i = 1 ; i <= k ; i++){
			if(mark[i]) ans += c[i];
		}
		for(int i = 1 ; i <= m ; i++) q[i] = p[i];
    	for(int i = 1 ; i <= k ; i++){
    		if(mark[i] == 0) continue;
    		for(int j = 1 ; j <= n ; j++){
    			for(int k = j + 1 ; k <= n && cnt <= m + 2 * n ; k++){
    				q[++cnt] = {j , k , a[i][j] + a[i][k]};
				}
			}
		}		
		sort(q + 1 , q + 1 + cnt , cmp);
		for(int i = 1 ; i <= n ; i++) fa[i] = i;
		for(int i = 1 ; i <= cnt ; i++){
			if(find(q[i].u) != find(q[i].v)){
				ans += q[i].w;
				fa[find(q[i].u)] = find(q[i].v);
			}
		}
		res = min(res , ans);
		return ;
	}
	mark[x] = 1;
	dfs(x + 1);
	mark[x] = 0;
	dfs(x + 1);
}
signed main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i++){
		int u , v , w;
		cin >> u >> v >> w;
		p[i] = {u , v , w};
	}
	cnt = m;
	for(int i = 1 ; i <= k ; i++){
		cin >> c[i];
		if(c[i] != 0) flag = false;
		for(int j = 1 ; j <= n ; j++){
			cin >> a[i][j];
		}
	}
	if(k == 0){
		sort(p + 1 , p + 1 + m , cmp);
		for(int i = 1 ; i <= n ; i++) fa[i] = i;
		int ans = 0;
		for(int i = 1 ; i <= m ; i++){
			if(find(p[i].u) != find(p[i].v)){
				ans += p[i].w;
				fa[find(p[i].u)] = find(p[i].v);
			}
		}
		cout << ans;
		return 0;
	}
    if(flag == true){
    	for(int i = 1 ; i <= k ; i++){
    		for(int j = 1 ; j <= n ; j++){
    			for(int k = j + 1 ; k <= n ; k++){
    				p[++cnt] = {j , k , a[i][j] + a[i][k]};
				}
			}
		}
		sort(p + 1 , p + 1 + cnt , cmp);
		for(int i = 1 ; i <= n ; i++) fa[i] = i;
		int ans = 0;
		for(int i = 1 ; i <= cnt ; i++){
			if(find(p[i].u) != find(p[i].v)){
				ans += p[i].w;
				fa[find(p[i].u)] = find(p[i].v);
			}
		}
		cout << ans;		
    	return 0;
	}
	dfs(1);
	cout << res;
	return 0;
}
