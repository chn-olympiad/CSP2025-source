#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 1e4 + 5;
const int M = 1e6 + 5;
int n, m, k;
int val[11];
int dis[11][N];
bool vis[11];
int ansi = (ll)1e18;

struct node {
    int x, y, w;
}edge[M], nedge[M << 1];

bool cmp(node x, node y) {
    return x.w < y.w;
}

int fa[N + 50], cnt;

int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

ll kruskal() {
    int tot = 0, nn = n, sum = 0;
    cnt = 0;
    for(int i = 1; i <= m; ++i)
        nedge[++tot] = edge[i];
    for(int i = 1; i <= k; ++i) {
        if(!vis[i]) continue;
        ++nn;
        for(int j = 1; j <= n; ++j)
            nedge[++tot] = node{nn, j, dis[i][j]};
    }
    sort(nedge + 1, nedge + tot + 1, cmp);
    for(int i = 1; i <= nn; ++i)
        fa[i] = i;
    for(int i = 1; i <= tot; ++i) {
        int x = nedge[i].x, y = nedge[i].y, w = nedge[i].w;
        int fx = find(x), fy = find(y);
        if(fx == fy) continue;
        fa[fx] = fy;
        sum += w;
        ++cnt;
        if(cnt == nn - 1) break;
    }
    return sum;
}

void dfs(int x, int sum) {
    if(sum >= ansi) return;
    if(x == k + 1) {
        // if(kruskal() + sum == 5182974424) {
        //     for(int i = 1; i <= k; ++i)
        //         if(vis[i])
        //             cout << i << " ";
        //     cout << "\n";
        // }
        ansi = min(ansi, kruskal() + sum);
        // cerr << sum << "\n";
        return;
    }
    if(val[x] == 0) {
        vis[x] = true;
        dfs(x + 1, sum);
        return;
    }
    vis[x] = false;
    dfs(x + 1, sum);
    vis[x] = true;
    dfs(x + 1, sum + val[x]);
}

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out","w", stdout);
    ios :: sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i)
        cin >> edge[i].x >> edge[i].y >> edge[i].w;
    for(int i = 1; i <= k; ++i) {
        cin >> val[i];
        for(int j = 1; j <= n; ++j)
            cin >> dis[i][j];
    }
    // vis[1] = true;
    // cout << kruskal();
    dfs(1, 0);
    cout << ansi;
    return 0;
}
/*
不想想了，随便打打。
我想写小作文。
就这样吧，我连题都不想看了，多一个提一少一个提一都无所谓
说得好像有什么升学优势一样。
反正想做什么就做什么好了。
*/
/*
即使启程与终程都不算完美，但至少我曾拥有过程。 ————前言

如果需要用一个词来定义 OI 生涯，那么我想它会是遗憾。

不仅仅是我的，我好像很难见到身边有一个以完美结局的 OI 生涯。拿了 NOIP 1= 的遗憾没进省队，进了省队的遗憾没拿 Ag，拿了 Ag 的遗憾没拿 Au，拿了 Au 的遗憾没进国集。
或许未来我身边会出现这样一段完美收官的 OI 生涯吧，毕竟即便是我们这一届的故事也还没有画上句号，更何况是前途未定的下面几届呢？

OI 是一场遗憾的梦。我梦见我是一名前途光明的选手，梦见我进了省队，梦见我参加了 NOI，梦见我拿到了我想拿到的。
我曾无数次试图掌控这个梦，幻想过无数种可能，来让遗憾消失。假如我在 HNOI2024 前不摆烂，假如我在 NOI2024 前没有迷失方向，假如我在 HNOI 2025 前没有出现心态问题，假如我在 HNOI2025 时发挥出了自己应有的水平…………一切是不是会不一样？
————但遗憾是消失不了的。我什么都没能做到，我成为不了曾经的自己梦想中的人，我抵达不了那个彼岸，我无法与我的 OI 生涯释怀。

我只能与曾经的理想告别，再也不与它相见。

OI 是一场遗憾的旅途。曾满心欢喜地踏上旅途，一次次更改着目的地，恍惚间来到了以前从未想象的远方，认识了以前从不曾有过交际的同行者，见到了以前从未i预料到的风景。比起文化课，这趟旅途让我遇见了更多来自天南海北的朋友，遇见了课本上不会出现的知识，去到了不同风格的城市，享受到了自由，体验到了竞赛的乐趣。
或许遗憾于曾经一起上车的朋友在中途下了车，没能一起到最后，但至少我们曾并肩通行过。或许遗憾于没能见到终点的风景，没能实现自己的理想，但至少我见过途中的风景。

虽然我也吐槽过彩票学竞赛，迷茫过 OI 给我带来了什么，虽然我的文化课现在也一团糟。但一位陪伴你大半个青春生涯的挚友，又怎么能一下子放下。我挣扎着，徘徊着，却不肯主动真正与它割舍。直到不得不下站，结束旅途的继续。

我在写些什么？我也不知道。总感觉要说的话很多，却不知怎么说出来。如果有人能看完这段话，如果很巧的是你的前途还正光明，那么我希望你能慎重考虑自己的 OI 水平最终想要达到哪一步。如果考虑不清，那也不要按照最低的要求学，万一你幸运地走到了后面，却遗憾于自己曾经没能付出全部努力而与他人有了难以横越的实力的断层，那时便已经为时已晚了。

我曾很难在洛谷上找到比自己年龄小的选手，我曾以为自己的 OI 生涯还长，我曾以为自己的比赛还有很多场，我曾以为自己的前途光明，我曾以为自己是那个例外，是那个奇迹。但我只是个普通人，一个普通的选手，一个普通的已经退役的选手。

在 HNOI2025 Day1 考完的那天晚上，我知道我把一切都弄砸了，我知道我辜负了曾经的自己，我知道我的 OI 生涯结束了。坐在假山上，我戴着耳机，抬起头，像曾经无数个夜晚那样透过树枝望向夜空。

————曾经在繁重学业中偷闲片刻的小孩，正喜欢躺在操场上望着星空，思考着过去，期待于未来，专注于当下能将幻想中的未来付诸现实的途径。然后将一切思绪放空，只是感受着微风拂过，只是听着不远处围栏外人群的喧嚣。

月光无言，星光依旧。

————竞赛生涯还漫长的少年们，在操场肆意挥写着自己的青春故事，意气风发，不知天高地厚，不必担心于仿佛很久之后才会经历的退役，不必约束在一次次无法容许失败的赛事里。那时候的赛季只有 CSP，那时候一次的失利也可以用第二年的成绩来弥补。

朦胧间，我仿佛看见有一只白鸟掠过了弯月，穿过漫漫黑夜，将我的梦想送回了过去。
————送回到那个一切都还有希望的过去。
*/