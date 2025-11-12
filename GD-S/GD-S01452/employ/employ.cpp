/*
一眼丁真,我不会做。
暴力，启动！

预期得分：1~2,6~8,16~17, 3~5剪剪枝说不定能干过几个,12~15加把劲看看能不能水过。
28~52分左右。 16：05

写完T2后来了一把小恐龙，喜提1635分，比全考场CSP-S复赛分都高（并不）。

打的还是太菜了呢。

不说那么多了，我们继续思考T4部分分。 16：50

其实O(n!)的算法也很有效率的，对吧。

上面的预期得分全是假的。16：54

+8pts 17：10

姬海棠果可爱滴捏——这句话能不能给我+8pts啊。

探女也可爱滴捏。探女探女快祝所有oier rp--。17：11

加的减枝仍无法肘击过n=18的数据，我放弃了。17：52

尝试写dp，但dp有容斥，我不会容斥。我是废物(´。＿。｀)。18：04
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 600, mod = 998244353;
int n, m, status[N], madness[N], used[N], fac[N], ans;
char op;
void dfs(int depth, int okay_cnt){
    if(depth == n + 1 && okay_cnt >= m) return ans = (ans + 1) % mod, void();
    if(okay_cnt == m) return ans = (0ll + ans + fac[n - depth + 1]) % mod, void();
    if(n - depth + 1 < m - okay_cnt) return;
    for(int i = 1; i <= n; i++){
        if(used[i]) continue;
        used[i] = 1;
        dfs(depth + 1, okay_cnt + (depth - okay_cnt - 1 < madness[i] && status[depth]));
        used[i] = 0;
    }
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m; fac[0] = 1;
    for(int i = 1; i <= n; i++) fac[i] = (1ll * i * fac[i - 1]) % mod;
    for(int i = 1; i <= n; i++) cin >> op, status[i] = op - '0';
    for(int i = 1; i <= n; i++) cin >> madness[i];
    dfs(1, 0);
    cout << ans << flush;
}
