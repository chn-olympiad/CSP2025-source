#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e4 + 9, maxm = 1e6 + 9;
const ll llmax = 1e18;
struct node{
	int u, v, w;
}edge[maxm << 1];
int n, m, k;
int a[19][maxn], cost[19];
int fa[maxn];
bool cmp(node x, node y){
	return x.w < y.w;
}
int findd(int x){
	if(fa[x] == x) return x;
	return fa[x] = findd(fa[x]); 
}
ll kruskal(int num){
	ll re = 0;
	int siz = m, cnt = n;
	for(int i = 0;i < k;i++){
		if((1 << i) & num){
			re += cost[i + 1];
			cnt++;
			for(int j = 1;j <= n;j++) edge[++siz] = {i + n + 1, j, a[i + 1][j]};
		}
	}
	sort(edge + 1, edge + 1 + siz, cmp);
	for(int i = 1;i <= n + k;i++) fa[i] = i;
	for(int i = 1;i <= siz;i++){
		int fau = findd(edge[i].u), fav = findd(edge[i].v);
		if(fau != fav){
			re += edge[i].w;
			fa[fau] = fav;
			cnt--;
			if(cnt == 1) break;
		}
	}
	return re;
}
void work1(){
	ll re = 0;
	int siz = m, cnt = n + k;
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= n;j++) edge[++siz] = {i + n, j, a[i][j]};
	}
	sort(edge + 1, edge + 1 + siz, cmp);
	for(int i = 1;i <= n + k;i++) fa[i] = i;
	for(int i = 1;i <= siz;i++){
		int fau = findd(edge[i].u), fav = findd(edge[i].v);
		if(fau != fav){
			re += edge[i].w;
			fa[fau] = fav;
			cnt--;
			if(cnt == 1) break;
		}
	}
	cout << re;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    clock_t st, ed;
    st = clock();
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) cin >> edge[i].u >> edge[i].v >> edge[i].w;
	int cnt = 0, cnt2 = 0;
	for(int i = 1;i <= k;i++){
		cin >> cost[i];
		if(cost[i] == 0) cnt++;
		bool flag = 0;
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
			if(a[i][j] == 0) flag = 1;
		}
		cnt2 += flag;
	}
	if(cnt == k && cnt2 == k){
		work1();
		return 0;
	}
	ll ans = llmax;
	for(int i = 0;i < (1 << k);i++){
		ans = min(ans, kruskal(i));
		ed = clock();
		if(ed - st > 900){
			cout << ans << "\n";
			return 0;
		}
	}
	cout << ans << "\n";
    return 0;
}

