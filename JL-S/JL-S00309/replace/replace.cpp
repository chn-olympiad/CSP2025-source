#include <bits/stdc++.h>
#define lowbit(x) x & -x
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef unsigned long long ULL;
const int N = 200005, P = 131;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
string s[N][2], t[N][2];
ULL hs[N][2];
vector<ULL> ht[N][2];
int ds[N], dt[N], pre[N * 2], suf[N * 2];
int tmp[N * 2], n, q;
LL ans[N];
struct Node{
    int x, y, id;
};
vector<Node> a[N * 2];
int tr[5000005], mxy;
ULL get(vector<ULL> &h,vector<ULL> &p,int l,int r)
{
    l ++, r ++;
    return h[r] - h[l - 1] * p[r - l + 1];
}
bool cmp(Node A,Node B)
{
    if (A.x != B.x)
        return A.x < B.x;
    if (A.y != B.y)
        return A.y < B.y;
    return A.id < B.id;
}
inline void add(int x,int y)
{
    for (x++;x<=mxy;x+=lowbit(x))
        tr[x] += y;
}
inline int ask(int x)
{
    int res = 0;
    for (x++;x;x-=lowbit(x))
        res += tr[x];
    return res;
}
void work()
{
    cin >> n >> q;
    for (int i=1;i<=n;i++)
        cin >> s[i][0] >> s[i][1];
    LL L2 = 0;
    for (int i=1;i<=q;i++)
    {
        cin >> t[i][0] >> t[i][1];
        if (t[i][0].size() == t[i][1].size())
            L2 += t[i][0].size() + t[i][1].size();
    }
    if (n * L2 <= 20000000)
    {
        vector<ULL> p;
        p.pb(1);
        for (int i=1;i<=n;i++)
            for (int j=0;j<=1;j++)
            {
                const int len = s[i][j].size();
                while (p.size() <= len)
                    p.pb(p.back() * P);
                ULL h = 0;
                for (int k=0;k<len;k++)
                    h = h * P + s[i][j][k];
                hs[i][j] = h;
            }
        for (int i=1;i<=q;i++)
        {
            if (t[i][0].size() != t[i][1].size())
            {
                cout << "0\n";
                continue;
            }
            const int len = t[i][0].size();
            for (int j=0;j<=1;j++)
            {
                while (p.size() <= len)
                    p.pb(p.back() * P);
                ht[i][j].resize(len + 1);
                for (int k=1;k<=len;k++)
                    ht[i][j][k] = ht[i][j][k - 1] * P + t[i][j][k - 1];
            }
            int last = len;
            while (last > 0 && t[i][0][last - 1] == t[i][1][last - 1])
                last --;
            int ans = 0;
            for (int k=0;k<len;k++)
            {
                for (int j=1;j<=n;j++)
                {
                    if (k + s[j][0].size() > len)
                        continue;
                    if (last > k + s[j][0].size())
                        continue;
                    if (get(ht[i][0], p, k, k + s[j][0].size() - 1) != hs[j][0])
                        continue;
                    if (get(ht[i][1], p, k, k + s[j][0].size() - 1) != hs[j][1])
                        continue;
                    ans ++;
                }
                if (t[i][0][k] != t[i][1][k])
                    break;
            }
            cout << ans << '\n';
        }
        // zhe ji zi zen me pao 3e10 pao le 5s
        return;
    }
    bool flag = true;
    for (int i=1;i<=n&&flag;i++)
        for (int j=0;j<=1&&flag;j++)
        {
            int cnt = 0;
            for (char k : s[i][j])
                if (k == 'b')
                    cnt ++;
                else if (k != 'a')
                {
                    flag = false;
                    break;
                }
            if (cnt != 1)
                flag = false;
        }
    for (int i=1;i<=q&&flag;i++)
    {
        if (t[i][0].size() != t[i][1].size())
            continue;
        for (int j=0;j<=1&&flag;j++)
        {
            int cnt = 0;
            for (char k : t[i][j])
                if (k == 'b')
                    cnt ++;
                else if (k != 'a')
                {
                    flag = false;
                    break;
                }
            if (cnt != 1)
                flag = false;
        }
    }
    if (!flag)
    {
        while (q--)
            cout << "0\n";
        return;
    }
    for (int i=1;i<=n;i++)
    {
        int p1 = 0, p2 = 0;
        for (int j=0;j<s[i][0].size();j++)
            if (s[i][0][j] == 'b')
            {
                p1 = j;
                break;
            }
        for (int j=0;j<s[i][1].size();j++)
            if (s[i][1][j] == 'b')
            {
                p2 = j;
                break;
            }
        tmp[i] = ds[i] = p1 - p2;
        pre[i] = p1, suf[i] = s[i][0].size() - p1 - 1;
    }
    for (int i=1;i<=q;i++)
    {
        if (t[i][0].size() != t[i][1].size())
            continue;
        int p1 = 0, p2 = 0;
        for (int j=0;j<t[i][0].size();j++)
            if (t[i][0][j] == 'b')
            {
                p1 = j;
                break;
            }
        for (int j=0;j<t[i][1].size();j++)
            if (t[i][1][j] == 'b')
            {
                p2 = j;
                break;
            }
        tmp[i + n] = dt[i] = p1 - p2;
        pre[i + n] = p1, suf[i + n] = t[i][0].size() - p1 - 1;
    }
    sort(tmp + 1, tmp + n + q + 1);
    int tot = unique(tmp + 1, tmp + n + q + 1) - tmp - 1;
    for (int i=1;i<=n;i++)
    {
        ds[i] = lower_bound(tmp + 1, tmp + tot + 1, ds[i]) - tmp;
        a[ds[i]].pb({pre[i], suf[i], 0});
    }
    for (int i=1;i<=q;i++)
    {
        if (t[i][0].size() != t[i][1].size())
            continue;
        dt[i] = lower_bound(tmp + 1, tmp + tot + 1, dt[i]) - tmp;
        a[dt[i]].pb({pre[i + n], suf[i + n], i});
    }
    for (int i=1;i<=tot;i++)
    {
        sort(a[i].begin(), a[i].end(), cmp);
        mxy = 0;
        for (Node j : a[i])
            mxy = max(mxy, j.y + 1);
        for (Node j : a[i])
            if (!j.id)
                add(j.y, 1);
            else
                ans[j.id] = ask(j.y);
        for (Node j : a[i])
            if (!j.id)
                add(j.y, -1);
    }
    for (int i=1;i<=q;i++)
        cout << ans[i] << '\n';
}
int main()
{
    freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _T = 1;
    //cin >> _T;
    while (_T--)
        work();
    return 0;
}