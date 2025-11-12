#include <iostream>
#include <vector>
#define int long long
#define endl "\n"
using namespace std;

vector<int> v;
int n, k;

int solve(int l)
{
    for (int j = l; j < n; j++)
    {
        for (int i = j; i >= l; i--)
        {
            if ((i >= 1 && (v[j] ^ v[i - 1]) == k) || (i == 0 && v[j] == k))
            {
                return 1 + solve(j + 1);
            }
        }
    }
    return 0;
}

signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    for (int i = 1; i < n; i++)
    {
        v[i] ^= v[i - 1];
    }
    cout << solve(0) << endl;
    return 0;
}
