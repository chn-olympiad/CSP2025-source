#include<bits/stdc++.h>
#define int long long
using namespace std;
const int NR = 1e4 + 5;
const int MR = 1e6 + 2e4 + 5;
const int KR = 15;
struct asdf{
	int u,v,w;
	bool operator < (const asdf &b) const{
		return w < b.w;
	}
};
int n,m,k;
asdf a[MR];
int c[KR];
bool xuan[KR];
int ans = 1e18,tot;
int fa[NR];
int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
inline int get_ans(int sum,int num){
	int res = sum;
	int cnt = 0;
	for(int i = 1;i <= n + k;i++) fa[i] = i;
	for(int i = 1;i <= tot;i++){
		if(cnt >= n + num - 1) break;
		if(a[i].u > n && !xuan[a[i].u - n]) continue;
		if(find(a[i].u) == find(a[i].v)) continue;
		fa[find(a[i].u)] = find(a[i].v);
		cnt++;
		res += a[i].w;
	}
	return res;
}
void dfs(int x,int sum,int num){
	if(x > k){
		ans = min(ans,get_ans(sum,num));
		return;
	}
	xuan[x] = 1;
	dfs(x + 1,sum + c[x],num + 1);
	xuan[x] = 0;
	dfs(x + 1,sum,num);
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	tot = m;
	for(int i = 1;i <= m;i++) cin >> a[i].u >> a[i].v >> a[i].w;
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			int x;
			cin >> x;
			a[++tot].u = n + i;
			a[tot].v = j;
			a[tot].w = x;
		}
	}
	sort(a + 1,a + tot + 1);
	dfs(1,0,0);
	cout << ans;
	return 0;
}

