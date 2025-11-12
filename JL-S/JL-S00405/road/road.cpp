#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 10005;
int n, m, k, cnt = 0, c[15], fa[N];
bool f = 1;
ll ans = 1000000000000000000;
struct node{
	int x, y, val, op;
	bool operator <(const node & s)const{
		return val < s.val;
	}
}a[1500005];
int getfa(int x){
	return x == fa[x] ? x : fa[x] = getfa(fa[x]);
}
void solve1(int s){
//	printf("\n%d\n", s);
	long long res = 0;
	int t = 0, num = 1;
	for(int i = 1;i <= 5;i++){
		if(s & (1 << (i - 1)))res += c[i];
	}
//	printf("%lld\n", res);
	for(int i = 1;i <= n;i++)fa[i] = i;
	while(t < n - 1){
		int x = a[num].x, y = a[num].y;
		int fx = getfa(x), fy = getfa(y);
		if(fx == fy){
			num++;continue;
		}
		if(a[num].op != 0 && !(s & (1 << (a[num].op - 1)))){
			num++;continue;
		}
//		printf("%d %d\n", x, y);
		fa[x] = y;
		res += a[num].val;
		num++;t++;
	}
	ans = min(ans, res);
//	printf("%lld\n", res);
}
void solve(){
	long long res = 0, t = 0, num = 1;
	for(int i = 1;i <= n;i++)fa[i] = i;
	while(t < n - 1){
		int x = a[num].x, y = a[num].y;
		int fx = getfa(x), fy = getfa(y);
		if(fx == fy){
			num++;continue;
		}
		fa[x] = y;
		res += a[num].val;
		num++;t++;
	}
	ans = min(ans, res);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	if(k == 0){
		priority_queue <node> q;
		for(int i = 1;i <= m;i++){
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			q.push({x, y, z, 0});
		}
		int cnt = 1;
		long long res = 0;
		while(cnt <= n - 1){
			node tt = q.top();q.pop();
			int x = tt.x, y = tt.y;
			int fx = getfa(x), fy = getfa(y);
			if(fx == fy)continue;
			fa[x] = y;
			res += tt.val;
			cnt++;
		}
		printf("%lld", res);
		return 0;
	}
	for(int i = 1;i <= m;i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[++cnt] = {x, y, z, 0};
	}
	for(int i = 1;i <= k;i++){
		scanf("%d", &c[i]);
		if(c[i])f = 0;
		for(int j = 1;j <= n;j++){
			int x;
			scanf("%d", &x);
			a[++cnt] = {i, j, x, i};
			if(i == j)c[i] += x;
		}
	}
	sort(a + 1, a + cnt + 1);
	if(f){
		solve();
	}else{
		for(int s = 0;s < (1 << n);s++){
			solve1(s);
		}
	}
	printf("%lld", ans);
	return 0;
}