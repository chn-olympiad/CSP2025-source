#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define mod 1000000000000007
#define bse 131
using namespace std;
typedef long long LL;

int n, q;
string s[200005][2];
LL bighsh(string s)
{
    int ans = 0;
    for (auto i : s) ans = (ans * bse + (i - 'a')) % mod;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    map<LL, LL> mp;
    for (int i = 1; i <= n; i++)
        cin >> s[i][0] >> s[i][1], mp[bighsh(s[i][0])] = bighsh(s[i][1]);
    while (q--)
    {
        string t1, t2;
        cin >> t1 >> t2;
        int l = t1.length();
        t1 = "#" + t1, t2 = "#" + t2;
        int mn = l, mx = 0;
        for (int i = 1; i <= l; i++)
            if (t1[i] != t2[i]) mn = min(mn, i), mx = max(mx, i);
        int ans = 0;
        for (int i = 1; i <= mn; i++)
        {
            LL nt1 = 0, nt2 = 0;
            for (int j = i; j <= mx - 1; j++)
                nt1 = (nt1 * bse + (t1[j] - 'a')), nt2 = (nt2 * bse + (t2[j] - 'a'));
            for (int j = mx; j <= l; j++)
            {
                nt1 = (nt1 * bse + (t1[j] - 'a')), nt2 = (nt2 * bse + (t2[j] - 'a'));
                if (mp.count(nt1) && mp[nt1] == nt2) ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
还剩一个小时作这道题
呜呜呜，这道题如果糊个 AC 自动机上去就能再拿 15 分了，但是我感觉我肯定已经忘了怎么写了。。。
怎么办怎么办怎么办怎么办怎么办怎么办怎么办怎么办怎么办怎么办怎么办怎么办怎么办怎么办

如果我们已经给定了一个字符串 s，那么就可以通过前缀和快速地求出某一段的哈希值
并且初始给定的 n 个字符串的哈希值可以预处理，只有 n 个
考虑在前缀哈希值中匹配这 n 个值值值值之值之值之值之值之值之值之值之值之值之
。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
没了～～。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
至此，期望得分 228
不要挂分，不要挂分，不要挂分，不要挂分，不要挂分，不要挂分，不要挂分！！！！！！！
完了我怎么感觉 B 题常数不太好，log(10000)÷log(2)×10000×1024 = 1.4e8。。。
没逝，我们有 CCF 少爷机
*/