#include<bits/stdc++.h>
using namespace std;
long long answ = 0x3f3f3f3f3f3f3f3f;
bitset <15> town;
int fa[10015], c[15], k;
struct P{
	int a, b, p;
} l[1100005];
int find(int x){
	if(fa[x] == x) return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
bool cmp(P x, P y){
	return x.p < y.p;
}
void bcj(int n, int m, int num, int pr){
	for(int i = 1; i <= n; i++) fa[i] = i;
	long long ans = pr;
	cout << ans << "\n";
	for(int i = 1; i <= m; i++){
		if(l[i].a > num && !town[l[i].a - num]) continue;
		if(find(l[i].a) != find(l[i].b)){
			ans += l[i].p;
			fa[l[i].a] = l[i].b;
		}
	}
	answ = min(answ, ans);
	return ;
}
void dfs(int now, int n, int m, int num, int pr){
	if(now > k){
		bcj(n, m, num, pr);
		return ;
	}
	town[now] = 0;
	dfs(now + 1, n, m, num, pr);
	town[now] = 1;
	dfs(now + 1, n + 1, m + num, num, pr + c[now]);
	town[now] = 0;
	return ;
}
int main(){
	freopen("road1.in", "r", stdin);
//	freopen("road.out", "w", stdout);
	int n, m;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) cin >> l[i].a >> l[i].b >> l[i].p;
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			int w;
			cin >> w;
			l[m + (i - 1) * n + j].a = n + i;
			l[m + (i - 1) * n + j].b = j;
			l[m + (i - 1) * n + j].p = w;
		}
	}
	for(int i = n + 1; i <= n + k + 1; i++) fa[i] = i;
	sort(l + 1, l + m + k * n + 1, cmp);
	dfs(1, n, m, n, 0);
	cout << answ;
	return 0;
}
