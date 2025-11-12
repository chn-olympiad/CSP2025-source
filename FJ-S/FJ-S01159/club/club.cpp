#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3 * 1e5 + 5;

int T, n, vis[N], c[4], ans, f[100005];

struct nnn{
	int a, b, c;
}b[100005];

struct node{
	int pos, v, id;
}a[N];

bool cmp(node x, node y){
	return x.v > y.v;
}

void dfs(int now, int c1, int c2, int c3, int v){
	if(now == n){
		ans = max(ans, v);
		return ;
	}
	if(c1 < (n / 2)){
		dfs(now + 1, c1 + 1, c2, c3, v + b[now + 1].a);
	}
	if(c2 < (n / 2)){
		dfs(now + 1, c1, c2 + 1, c3, v + b[now + 1].b);
	}
	if(c3 < (n / 2)){
		dfs(now + 1, c1, c2, c3 + 1, v + b[now + 1].c);
	}
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T --){
		ans = 0;
		cin >> n;
		if(n == 2){
			int u, v, w, x, y, z;
			cin >> u >> v >> w >> x >> y >> z;
			ans = max(ans, u + y);
			ans = max(ans, u + z);
			ans = max(ans, v + x);
			ans = max(ans, v + z);
			ans = max(ans, w + x);
			ans = max(ans, w + y);
			cout << ans << '\n';
		}
		else if(n <= 30){
			for(int i = 1 ; i <= n ; i ++){
				cin >> b[i].a >> b[i].b >> b[i].c;
			}
			dfs(0, 0, 0, 0, 0);
			cout << ans << '\n';
		}
		else{
			bool flag = 1;
			for(int i = 1 ; i <= n ; i ++){
				cin >> b[i].a >> b[i].b >> b[i].c;
				if(b[i].c) flag = 0;
			}
			if(flag){
				for(int i = 1 ; i <= n ; i ++){
					for(int j = n / 2 ; j >= 0 ; j --){
						f[j] = f[j] + b[i].b;
						if(j){
							f[j] = max(f[j], f[j - 1] + b[i].a);
						}
					}
				}
				for(int i = 0 ; i <= n / 2 ; i ++){
					ans = max(ans, f[i]);
				}
				cout << ans << '\n';
				continue;
			}
			int cnt = 0;
			c[1] = c[2] = c[3] = 0;
			for(int i = 1 ; i <= n ; i ++){
				vis[i] = 0;
				a[++ cnt].v = b[i].a;
				a[cnt].pos = i;
				a[cnt].id = 1;
				a[++ cnt].v = b[i].b;
				a[cnt].pos = i;
				a[cnt].id = 2;
				a[++ cnt].v = b[i].c;
				int x = a[cnt].v;
				a[cnt].pos = i;
				a[cnt].id = 3;
			}
			sort(a + 1, a + cnt + 1, cmp);
			for(int i = 1 ; i <= cnt ; i ++){
				if(vis[a[i].pos]) continue;
				if(c[a[i].id] == (n / 2)) continue;
				vis[a[i].pos] = 1;
				c[a[i].id] ++;
				ans += a[i].v;
			}
			cout << ans << '\n';
		}
			
	}
	return 0;
}
// 贪心是假的！！！！！！！！！！！！！ T^T 
// 不会做了!!!!!!!!!!!!!
// 你第一题扔个 dp 我做什么
// 第二题图论可能会做调不出来怎么办 
// 我真的求你了到底怎么做 
// 没一道会做了
// 笑死CSP-S2024的分数比 CSP-S2025的高
// 怎么办我要破防了 
// 求你了1=分数线105吧 
// 预计得分 35 
