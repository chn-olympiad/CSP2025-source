/*
## 看题
这下这下了, 我的闹钟怎么死了
start 2:30, lst 240min

### T1
糖糖题

### T2
别别别

### T3
猎奇, 真出串串啊

### T4
数数不会

## T1
策略, 停滞, 解决, 心态
数据检验, 关键步记录, 理清过程
### 思路
不难发现贪心分配之后仅存在唯一部门可能多于 n/2 个新成员
考虑调整到其它部门即可

对于最终多于 n/2 的那个部门, 统计其中员工的 △ 最小的那些丢到其它部门即可

## T2
策略, 停滞, 解决, 心态
数据检验, 关键步记录, 理清过程
### 思路
lhs 看到图论直接飞起来

首先简单归纳一下问题
1. 可以用 w_i 的花费修复一条边
2. 可以用 c_i 的花费激活一个中介点, 然后用 a_{i, j} 的花费将点 j 连接到中介点 i 上

最终要求原来的 n 个点联通的最小花费

woc k <= 10

---
首先 2^k 激活中介点
然后连上 (u, v, min_{i ∈ S} a_{i, u} + a_{i, v}), 跑一遍最小生成树就行了
真的吗?

> 知道为什么坐立难安了, 原来是没法翘板凳

原来大概不能直接做, 继续思考
我草那个完全图最小生成树的算法忘完了

哦哦哦不能这么做
我是[CCF比赛是不是要数据删除]
---

好的好的, 继续想
如果我们只保留最初的最小生成树的边, 正确性如何?
不难发现是正确的

## T3
策略, 停滞, 解决, 心态
数据检验, 关键步记录, 理清过程
### 思路
这题只有拼暴力
首先最暴力的做法就是对于每个询问, 暴力找出包含不同段的 s_i, 然后直接替换
对于特殊性质 A, 直接用暴力做法就可以弄完
对于特殊性质 B, 可能需要研究一下, 但是大概就是求 b 的移动距离即可

这题需要一定的时间

## T4
策略, 停滞, 解决, 心态
数据检验, 关键步记录, 理清过程
### 思路
快速想点低档暴力去做 T2

A 是全排列
B 是状态压缩, 但是不太会啊
*/
#include <bits/stdc++.h>
#define int long long
#define lowbit(x) ((x) & (-x))
const int MAXN = 2e5 + 20;
const int MAXV = 5e6 + 20;

int n, q;
std::string s[MAXN][2], t[MAXN][2];

std::vector<std::pair<int, int> > val[MAXV << 1];


signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%lld %lld", &n, &q);
    for (int i = 1; i <= n; i++) { 
        std::cin >> s[i][0] >> s[i][1];
        int pos1 = -1, pos2 = -1;
        for (int c = 0; c < s[i][0].length(); c++) {
            if (s[i][0][c] == 'b') pos1 = c;
        }
        for (int c = 0; c < s[i][1].length(); c++) {
            if (s[i][1][c] == 'b') pos2 = c;
        }
        
        val[pos1 - pos2 + 5000000].push_back({pos1, s[i][1].length()});
    }
    for (int i = 0; i <= 10000000; i++) {
        if (val[i].size()) {
            std::sort(val[i].begin(), val[i].end());
        }
    }
    for (int i = 1; i <= q; i++) {
        std::cin >> t[i][0] >> t[i][1];
        int pos1 = -1, pos2 = -1;
        if (t[i][0].length() != t[i][1].length()) {
            printf("0\n");
            continue;
        }
        for (int c = 0; c < t[i][0].length(); c++) {
            if (t[i][0][c] == 'b') pos1 = c;
        }
        for (int c = 0; c < t[i][1].length(); c++) {
            if (t[i][1][c] == 'b') pos2 = c;
        }
        
        int dif = pos1 - pos2 + 5000000;
        int mamba = 0;
        for (int i = 0; i < val[dif].size(); i++) {
            int pos = val[dif][i].first, len = val[dif][i].second;
            if (pos1 >= pos && t[i][1].length() - pos1 >= len - pos) mamba++;
        }
        printf("%lld\n", mamba);
    }
    
    return 0;
}