#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 998244353, N = 505;
int n, m, c[N];
string s;

namespace TT {
  int p[N];
  inline void solve() {
    for (int i = 1; i <= n; i++) p[i] = i;
    int ans = 0;
    do {
      int off = 0, cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (off >= c[p[i]]) off++;
        else if (s[i] == '1') cnt++;
        else off++;
      }
      if (cnt >= m) ans++;
    } while (next_permutation(&p[1], &p[n + 1]));
    cout << ans % P << "\n";
  }
}
namespace AA {
  int f[19][1 << 18];
  inline void solve() {
    f[0][0] = 1;
    for (int S = 0; S < (1 << n) - 1; S++) {
      int cnt = __builtin_popcount(S);
      for (int j = 0; j <= cnt; j++)
        if (f[j][S])
          for (int i = 1; i <= n; i++)
            if (~S >> (i - 1) & 1) {
              int no = (j >= c[i] || s[cnt + 1] == '0');
              (f[j + no][S | (1 << (i - 1))] += f[j][S]) %= P;
            }
    }
    int ans = 0;
    for (int j = 0; j <= n - m; j++) (ans += f[j][(1 << n) - 1]) %= P;
    cout << ans << "\n";
  }
}

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> s;
  s = " " + s;
  for (int i = 1; i <= n; i++) cin >> c[i];
  if (0 && n <= 10) TT::solve();
  else if (n <= 18) AA::solve();
  else cout << 0 << "\n";
  return 0;
}

/*
赛时状态：
- 14:37 看 T1
  - 最优化问题
  - 我们先假设每个人都去最喜欢的社团，然后最多一个不满足要求的社团，我们从里面踢人就好。
- 14:50 提交 T1，开了 long long
  - T2 是 MST 类问题，有 n 个点 m 条边的带权无向图，然后 k 个独立的虚点，每个虚点可以向任意原来的 n 个点连边，这样的 MST
  - 用 DFS 加入边枚举应该可以做到 2^{10}n
- 14:14 提交 T2，大样例跑得飞快，但是不确定是不是极端数据，之后有时间对拍。
  - T3 是字符串问题，给定一些字符串二元组，多次查询给出两个长度相同的字符串 s,t 求有多少 [l,r] 满足 s,t 在 [l,r] 外的地方一样，且 s[l,r],t[l,r] 是一个给出的二元组。
  - 题目保证给出的询问是两个不同的字符串，所以至少有一个不同的位置，那么 [l,r] 必须包含所有不一样的位置
  - 考虑字符串哈希
- 15:37 打算现看看 T4
  - 可能类似杨表计数？
  - 其实是每个人有一个固定的前缀。
  - 不是它这个描述有歧义吧，万一放弃面试的人的题目是简单题呢？到底算不算过？
  - 哦哦哦我觉得应该是不算过的。
  - 哦噢知道了，这个题目的难点在于前面放弃的也会影响后面的人。
- 懂了，现在还有不到 3h 我觉得应该现把 T3 做了然后拿 T4 暴力，最后全力冲刺 T4
  - T3 考虑一次询问怎么做？
  - 5e6 1s 应该不能搞根号的东西了，但是这道题有 2G
  - 线性的东西考虑 KMP 和字符串哈希。
  - 不能每次枚举 s，所以把 s1 丢到 trie 上看看
    - 每次沿着 t 走 trie，能匹配的 s 是所有的 fail tree 祖先链的点。
    - 然后我需要查询这些点是否有换成对应长度的 t2？
  - 我们建两个 trie
  - 我们可以把 s1 s2 放到一个 trie 里面，然后同时走 t1t2，那么走到 [l,r] 的有端点时，就是从这个位置网上 s1 在到 s2 就是 t2
  - 怎么这么难，怎么快速找树上一个点祖先能崩到另一个点的祖先。
  
  - 一个替换可能有多次贡献吗？不可能
  
  - 反过来吗？对询问 t 放到 trie 上
  
  
  - 感觉 trie 好难看清楚，现考虑特殊性质
    - 只有 a 和 b 且 b 恰好一个。
    
  - 16:13 考虑枚举 l
  - 找到最小的不同区间 [l,r] 你发现 l,r 是 s1s2 的子串
  - 推出 s1s2 的最小不一样区间也是 [l,r]
  - 所以应该是一个简单的字符串哈希
  - 我们根据最小不一样区间 将 s1s2 和 t1t2 分组，每组的所有 s1s2t1t2 的最小不一样区间相同，变成一个子串问题
  - 我们把这个不一样的位置换乘为出现的字符就好
  - 这是沙阿
  - 双重子串问题，我们可以让字符串交叉，这样就是普通子串问题了。
  - 还有两个小时了，最后一题还不会，所以尽量在 1h 内拿下 T3
  - 用字符串哈希处理寻找，然后用 trie 计算子串数量
  
  - 怎么写着感觉不对啊，这个 26 *node 真的能在 1s 跑完吗？
  - 都固定子串的一个位置了，那么肯定有更快的办法
  - 哦哦哦我们可以枚举左边对右边作字符串哈希。
  - 这样是 O(n) 的
  - 16:59 决定放弃 T4，先写 T4 部分分然后搞 T3
  - 17:11 T4 提交 20 分，开始冲 T3
  - 17:26 写完了 T3
  - 17:41 T3 通过所有下发数据，提交
- 17:43 打算搞 T4，然后留 一些时间写 T3 对拍
  - T4 n<=500 看起来是 DP
  - 考虑特殊性质 A
    - 那么只需要看
- 18:11 T4 对拍 400 组，正确性应该没问题
  - 只有 ab 的极端数据时间在 0.4s 左右
*/