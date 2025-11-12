#include <bits/stdc++.h>
#define int long long
using namespace std;
int r[500005], xs[500005];
struct
{
    int l, r, sum;
    bool lz;
} tr[3000006];
void build(int i, int l, int r)
{
    tr[i].l = l;
    tr[i].r = r;
    if (l != r)
    {
        int mid{l + r >> 1};
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
    }
}
void modify(int i, int l, int r)
{
    if (r < tr[i].l || l > tr[i].r)
        return;
    if (l <= tr[i].l && r >= tr[i].r)
        tr[i].lz = true, tr[i].sum = tr[i].r - tr[i].l + 1;
    if (!tr[i].lz)
    {
        modify(i << 1, l, r);
        modify(i << 1 | 1, l, r);
        tr[i].sum = tr[i << 1].sum + tr[i << 1 | 1].sum;
    }
}
int query(int i, int l, int r)
{
    if (r < tr[i].l || l > tr[i].r)
        return 0;
    if (l <= tr[i].l && r >= tr[i].r)
        return tr[i].sum;
    if (tr[i].lz)
        return min(tr[i].r, r) - max(tr[i].l, l) + 1;
    return query(i << 1, l, r) + query(i << 1 | 1, l, r);
}
signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, t{}, mxr{};
    cin >> n >> k;
    build(1, 1, n);
    for (int i{1}; i <= n; i++)
        cin >> r[i], xs[i] = xs[i - 1] ^ r[i], mxr = max(mxr, r[i]);
    if (k < 2 && mxr < 2)
    {
        if (k)
            cout << accumulate(r + 1, r + n + 1, 0);
        else
        {
            int t{};
            for (int i{1}; i <= n; i++)
                if (!r[i])
                    t++;
                else if (r[i + 1])
                    t++, i++;
            cout << t;
        }
        return 0;
    }
    for (int len{1}; len <= n; len++)
        for (int i{1}; i <= n - len + 1; i++)
        {
            int j{i + len - 1};
            // cout << i << ' ' << j << ' ' << query(1, i, j) << endl;
            if ((xs[j] ^ xs[i - 1]) == k && !query(1, i, j))
                t++, modify(1, i, j) /*, cout << query(1, i, j) << endl*/;
        }
    cout << t;
    return 0;
}
