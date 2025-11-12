#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 5;

struct Node
{
    int L;
    int R;
} seq[MAXN];

ll arr[MAXN];
ll S[MAXN];
ll n, k;
ll sel;

bool cmp(Node X, Node Y)
{
    if (X.R != Y.R) return X.R < Y.R;
    else return X.L > Y.L;
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        S[i] = S[i - 1] ^ arr[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            if ((S[j] ^ S[i - 1]) == k)
            {
                seq[++sel] = {i, j};
            }
        }
    }

    sort(seq + 1, seq + sel + 1, cmp);

    ll NowR = 0;
    ll tot = 0;

    for (int i = 1; i <= sel; ++i)
    {
        if (seq[i].L > NowR)
        {
            ++tot;
            NowR = seq[i].R;
        }
    }

    cout << tot << '\n';

    return 0;
}