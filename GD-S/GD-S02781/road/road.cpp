#include<bits/stdc++.h>
using namespace std;
#define int long long
struct point{
	int x,y,w;
}a[100005],t[5500005];
struct node{
	int v,d[10005];
}b[15];
bool cmp(point a,point b){
	return a.w < b.w;
}
int n,m,k;
int fa[10015];
int sum = 0;
bool use[15];
int s[15];
int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void Kruskal(int rn){
	int tot = m,cnt = 0;
	for(int i = 1;i <= m;i++) t[i] = a[i];
	for(int i = 1;i <= rn;i++){
		cnt = cnt + b[s[i]].v;
		for(int j = 1;j <= n;j++){
			for(int k = j + 1;k <= n;k++){
				t[++tot] = {j,k,b[s[i]].d[j]+b[s[i]].d[k]};
			}
		}
	}
	for(int i = 1;i <= n + rn;i++) fa[i] = i;
	sort(t+1,t+1+tot,cmp);
	for(int i = 1;i <= tot;i++){
		int x = t[i].x,y = t[i].y,w = t[i].w;
		x = find(fa[x]),y = find(fa[y]);
		if(x == y) continue;
		cnt = cnt + w;
		fa[y] = x;
	}
	if(sum == 0) sum = cnt;
	else sum = min(sum,cnt);
}
void dfs(int cur,int rn){
	if(cur == rn + 1){
		Kruskal(rn);
		return;
	}
	for(int i = s[cur-1] + 1;i <= k;i++){
		if(use[i]) continue;
		s[cur] = i;
		use[i] = true;
		dfs(cur + 1,rn);
		use[i] = false;
	}
}
void work(){
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> a[i].x >> a[i].y >> a[i].w;
	}
	if(k == 0){
		sort(a+1,a+1+m,cmp);
		int ans = 0;
		for(int i = 1;i <= n;i++) fa[i] = i;
		for(int i = 1;i <= m;i++){
			int x = a[i].x,y = a[i].y,w = a[i].w;
			x = find(fa[x]),y = find(fa[y]);
			if(x == y) continue;
			ans = ans + w;
			fa[y] = x;
		}
		cout << ans;
	}
	else{
		for(int i = 1;i <= k;i++){
			cin >> b[i].v;
			for(int j = 1;j <= n;j++){
				cin >> b[i].d[j];
			}
		}
		sort(a+1,a+1+m,cmp);
		for(int i = 1;i <= n;i++) fa[i] = i;
		for(int i = 1;i <= m;i++){
			int kx = a[i].x,ky = a[i].y,kw = a[i].w;
			kx = find(fa[kx]),ky = find(fa[ky]);
			if(kx == ky) continue;
			sum = sum + kw;
			fa[ky] = kx;
		}
		for(int i = 1;i <= k;i++){
			dfs(1,i);
		}
		cout << sum;
	}
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		work();
		if(t) cout << endl;
	}
}
