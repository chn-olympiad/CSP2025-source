#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct rm
{
    int l, r;
};

int n, k;
long long ans = 0;
vector<int> pre;
vector<rm> pos;

bool compare(rm x, rm y)
{
    return x.r < y.r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;

    pre.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        pre[i] = pre[i - 1] ^ x;
    }

    for (int l = 1; l <= n; l++)
    {
        for (int r = l; r <= n; r++)
        {
            long long w = pre[r] ^ pre[l - 1];

            if (w == k)
            {
                pos.push_back({l, r});
            }
        }
    }

    sort(pos.begin(), pos.end(), compare);
    int minr = 0;
    for (const rm& e : pos)
    {
        if (e.l > minr)
        {
            minr = e.r;
            ans++;
        }
    }
    cout << ans;
    return 0;
}
