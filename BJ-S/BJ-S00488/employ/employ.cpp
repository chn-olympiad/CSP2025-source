/*
15.13写完T1
15.53想出T2 48分做法 先二进制枚举k个乡村是否改造，再O(n^2)最小生成树
16.49写完T2 48分做法，过大样例，想T3 T4暴力
16.52开写T3哈希暴力O(nL),25pts
17.14写完T3 25哈希暴力，上个厕所休息一下
17.20想出T4 n!暴力DFS剪枝，8pts,我在想是写这8分的DFS还是回去测试T1-T3？
17.21我决定写T4 8分代码
17.49写完T4暴力，发现T4的特殊性质一个不会做，我决定能得8分是8分
外面的钟在17.59.48就响了  （：
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int n, m, c[N], ans;
string s;
bool used[N];
void DFS(int x, int now)//now: 到现在为止有多少人录用
{
    if(x == n + 1 && now >= m)
    {
        ++ans;
        return;
    }
    if(n - x + 1 + now < m)
        return;
    for(int i = 1;i <= n;i++)
    {
        if(used[i])
            continue;
        if(x - 1 - now >= c[i] || s[x] == '0')
        {
            used[i] = true;
            DFS(x + 1, now);
            used[i] = false;
        }
        else
        {
            used[i] = true;
            DFS(x + 1, now + 1);
            used[i] = false;
        }
    }
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    s = "#" + s;
    for(int i = 1;i <= n;i++)
        cin >> c[i];
    memset(used, false, sizeof(used));
    DFS(1, 0);
    cout << ans << '\n';
    return 0;
}