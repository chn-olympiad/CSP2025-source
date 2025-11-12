/*
ERIN!ERIN!TASUKETE!
KIOMOHIKEIRU!
（背错歌词了的话请不要打我QAQ）

ArisakaMashiro可爱滴捏喵，同时也是我的洛谷账户名谢谢喵，关注ArisakaMashiro谢谢喵，否则Mashiro酱就要用 Flying Circus 中使用的反重力鞋狠狠地踢你的铍鼓了喵。

但是自己是不能关注自己的，所以让我先来（大雾）。

===============================分隔符==================================

k <= 10,这是个很强的约束。
能不能考虑枚举？这是个问题。
并不能,2^10=1e3,跑不了kruskal力。

或许可以考虑优化这一过程。

但还没有想法。 15：36

我们考虑kruskal的本质，贪心。
设dp_{i, j} 表示在选择的目标点状态为 $i$ 的情况下（此处显然使用状压即可），考虑编号在前 $j$ 个点时的最小花费。
感觉是可以转移的。

这一部分的时间复杂度O（2^k * n）。

问题在于形成森林后的几个并查集之间如何求解最小值。暴力扫边集的时间复杂度不能保证正确。 15：45

上面的不对，这个dp有后效性。15：51

1.048s，大样例3。

中山纪中你最好给我用的是烂电脑（威胁）。

吸了氧之后变成0.627s了！赢！

希望最后 9 个测试点也能保持如上成绩（祈祷nia）。

TASUKETE_ERINNNNNNNNNN!!!!!!!!!!!!!!!

这份代码的时间复杂度......多少有点乱搞成分在。

O(2^k * (m + k * n) log (k * n))，能过的话多少带点玄学成分。

主要是 m + k * n 那项很难真正跑满，相信数据！ 16：44
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 2e6, N = 1e4 + 1e3, T = 15;
struct edge { 
    int l, r, w; 
    bool operator < (const edge& a) const { return w < a.w; }
} alle[M], newe[M];
int n, m, k, u, v, w, node_cnt, basic_cost[T], to_each[T][N], max_cnt, f[N];
int find(int x){
    if(f[x] == x) return x;
    return f[x] = find(f[x]);
}
ll cost, ans = 1e18;
void init(int enable_id){
    cost = max_cnt = 0; node_cnt = n;
    for(int i = 0; i < k; i++) {
        if(!((enable_id >> i) & 1)) continue;
        node_cnt++, cost += basic_cost[i];
        for(int j = 1; j <= n; j++) newe[++max_cnt] = {n + i + 1, j, to_each[i][j]};
    }
    for(int i = 1; i <= n + k; i++) f[i] = i;
    sort(newe + 1, newe + 1 + max_cnt);
}
ll kruskal(int enable_id){
    init(enable_id);
    for(int cnt = 0, l = 1, r = 1; cnt < node_cnt - 1; ){
        edge e;
        if(r <= max_cnt && alle[l].w > newe[r].w) e = newe[r++];
        else e = alle[l++];
        
        if(find(e.l) == find(e.r)) continue;
        f[find(e.l)] = find(e.r), cost += e.w, cnt++;
    }
    return cost;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) cin >> u >> v >> w, alle[i] = {u, v, w};
    sort(alle + 1, alle + 1 + m);
    for(int i = 0; i < k; i++) {
        cin >> basic_cost[i];
        for(int j = 1; j <= n; j++) cin >> to_each[i][j];
    }
    for(int i = 0; i < (1 << k); i++) ans = min(ans, kruskal(i));
    cout << ans << flush;
}
