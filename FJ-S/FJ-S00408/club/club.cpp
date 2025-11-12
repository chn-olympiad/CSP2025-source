#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
bool vis[N];
long long ans = -1;
struct e{
	int s, id;
}a[N], b[N], c[N];
/*
void dfs(int f1, int f2, int f3, int now, int cnt){
	if(cnt == n){
		ans = max(ans, (long long)now);
		return;
	}
	if(f1 + 1 <= (n / 2)){
		for(int i = n ; i <= 1 ; i ++){
			if(!vis[i]){
				vis[i] = true;
				dfs(f1 + 1, f2, f3, now + a[i], cnt + 1);
				vis[i] = false;
			}
		}
	}
	if(f2 + 1 <= (n / 2)){
		for(int i = n ; i <= 1 ; i ++){
			if(!vis[i]){
				vis[i] = true;
				dfs(f1, f2 + 1, f3, now + b[i], cnt + 1);
				vis[i] = false;
			}
		}
	}
	if(f3 + 1 <= (n / 2)){
		for(int i = n ; i <= 1 ; i ++){
			if(!vis[i]){
				vis[i] = true;
				dfs(f1, f2, f3 + 1, now + c[i], cnt + 1);
				vis[i] = false;
			}
				
		}
	}
}*/

bool cmp(e f, e ff){
	if(f.s == ff.s)
		return f.id > ff.id;
	return f.s > ff.s;
}
void dfs(int f1, int f2, int f3, long long now, int cnt){
	if(cnt == n){
		ans = max(ans, now);
		return;
	}
	for(int i = 1 ; i <= n ; i ++){
		if(!vis[a[i].id] && f1 + 1 <= n / 2){
			vis[a[i].id] = 1;
			dfs(f1+1, f2, f3, now + a[i].s, cnt+1);
			vis[a[i].id] = 0;
		}
		if(!vis[b[i].id] && f2 + 1 <= n / 2){
			vis[b[i].id] = 1;
			dfs(f1, f2 + 1, f3, now + b[i].s, cnt+1);
			vis[a[i].id] = 0;
		}
		if(!vis[c[i].id] && f3 + 1 <= n / 2){
			vis[c[i].id] = 1;
			dfs(f1, f2, f3+1, now + c[i].s, cnt+1);
			vis[a[i].id] = 0;
		}
	}
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	bool flag = 0;
	int T;
	cin >> T;
	while(T--){
		ans = 0;
		memset(vis, 0, sizeof(vis));
		cin >> n;
		for(int i = 1 ; i <= n ; i ++){
			cin >> a[i].s >> b[i].s >> c[i].s;
			a[i].id = b[i].id = c[i].id = i;
			if(b[i].s != 0 || c[i].s != 0)
				flag = 1;
		}
		sort(c + 1, c + n + 1, cmp);
		sort(b + 1, b + n + 1, cmp);
		sort(a + 1, a + n + 1, cmp);
		if(!flag){
			for(int i = 1 ; i <= n /2; i ++){
				ans += a[i].s;
			}
			cout << ans << "\n";
			return 0;
		}
		dfs(0,0,0,0,0);
		cout << ans << "\n";
	}
	return 0;
}
