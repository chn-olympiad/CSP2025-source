#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
#define endl "\n"
using namespace std;
const int mod = 998244353;

vector<int> v;
int m[5001];
int pows[5001];

int qpow(int a, int p)
{
    if (pows[p]) return pows[p] % mod;
    if (p == 0) return 1;
    if ((p & 1) == 0)
    {
        pows[p / 2] = qpow(a, p / 2) % mod;
        return pows[p] = (pows[p / 2] % mod * pows[p / 2] % mod) % mod;
    }
    if ((p & 1) == 1)
    {
        pows[p / 2] = qpow(a, p / 2) % mod;
        return pows[p] = (pows[p / 2] % mod * pows[p / 2] % mod * a) % mod;
    }
    return 1;
}

int dfs(int l, int sum, int maxn, int chosen, int amount)
{
    if (sum > maxn) return qpow(2, v.size() - l - 1) % mod;
    int ans = 0;
    for (int i = l + 1; i < v.size(); i++)
    {
        ans += dfs(i, sum + v[i], maxn, chosen + 1, amount) % mod;
        ans %= mod;
    }
    return ans % mod;
}

signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    bool subtask3 = true;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t > 1) subtask3 = false;
        v.push_back(t);
    }
    if (n == 3)
    {
        if ((v[0] + v[1] + v[2]) > max({v[0], v[1], v[2]}) * 2)
        {
            cout << 1 << endl;
        }
        else cout << 0 << endl;
        return 0;
    }
    else if (subtask3 == true)
    {
        cout << qpow(2, n) - n * (n - 1) / 2 - n - 1 << endl;
        return 0;
    }
    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            ans += dfs(j, v[j], v[i], 1, n - i - 1) % mod;
            ans %= mod;
        }
    }
    cout << ans % mod << endl;
    return 0;
}