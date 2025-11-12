#include <bits/stdc++.h>
//#define int long long
#define rep(x, y, z) for(int x = (int)(y);x <= (int)(z);x++)
#define per(x, y, z) for(int x = (int)(y);x >= (int)(z);x--)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
typedef long long ll;
const int N = 2e4 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3fll;
using namespace std;
struct edge{
	int u, v, w;
};
vector<edge> e;
int n, m, k, u, v, w, c[15], a[15][N], fa[N];
bool b[N];
int getfa(int id){
	if(fa[id] == id) return id;
	return fa[id] = getfa(fa[id]);
}
bool cmp(edge x, edge y){
	return x.w < y.w;
}
// 注意重边！！！！！！！
// 诶，是不是不判也没事
// 记得造组重边测一下 
ll calc(int val){
	ll ret = 0;
	int lst = n;
	rep(i, 1, n + k) fa[i] = i;
	rep(i, 0, k - 1) if((val >> i) & 1) ret += c[i + 1], lst++;
	for(auto i : e){
//		printf("u = %d, v = %d, w = %d\n", i.u, i.v, i.w);
		if(i.u > n && !((val >> (i.u - n - 1)) & 1)) continue;
		if(i.v > n && !((val >> (i.v - n - 1)) & 1)) continue;
		if(getfa(i.u) == getfa(i.v)) continue;
//		printf("add\n");
		ret += i.w;
		fa[getfa(i.u)] = getfa(i.v);
		lst--;
		if(lst == 1) break;
	}
//	printf("val = %d, ret = %lld\n", val, ret);
	return ret;
}
void solve(){
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, m){
		scanf("%d%d%d", &u, &v, &w);
		if(u > v) swap(u, v);
		e.pb({u, v, w});
	}
	rep(i, 1, k){
		scanf("%d", &c[i]);
		rep(j, 1, n) scanf("%d", &a[i][j]), e.pb({j, n + i, a[i][j]});
	}
	sort(e.begin(), e.end(), cmp);
	ll ans = inf;
	rep(i, 0, (1 << k) - 1) ans = min(ans, calc(i));
	printf("%lld\n", ans);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int T = 1;
//	scanf("%d", &T);
	while(T--) solve();
	return 0;
}
// 我不行了，这种板子也能在 T2
// 不对这题位置是绿，那没事了
// update: 复杂度算错了，我不行了 
/*
好的，现在又来到了去年的局面
去年因为 T2 感觉被卡常调了 2h，痛失 T3 100pts
今年样例 3 跑了 1.5s，好像复杂度还是错的，64->100 or T3
/lh 

手造最大点 2.5s，但是 gen 跑了 3.5s，what should i do
当然是搞个 hack
被卡到 10s 了！111 

先去看看 T3
能不能说我这次复刻了上一次，，上次也是 5 点调完，这次是写 T3 写到发现假了再回来搞 T2 发现 5 点了 
*/
// 100 + [64, 100] + 0 + 15 = [179, 215]
// 如此成绩，如何 NOIP？如此成绩，如何 NOIP？如此成绩，如何 NOIP？
