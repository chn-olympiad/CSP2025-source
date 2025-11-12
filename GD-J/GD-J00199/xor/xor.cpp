#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int ull

const int N = 5e5 + 10;

int n, k, a[N], ans;
unordered_set<int> st;

constexpr int mix64(const int &x)
{
    return x * 0x1145141919810CCFull;
}

signed main()
{
    if (1)
    {
        freopen("xor.in", "r", stdin);
        freopen("xor.out", "w", stdout);
    }
    cin.tie(0)->sync_with_stdio(0), cout << fixed << setprecision(10);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    st.insert(mix64(0));
    for (int i = 1, sum = 0; i <= n; ++i)
    {
        sum ^= a[i];
        if (st.count(mix64(sum ^ k)))
        {
            ++ans;
            st.clear();
            st.insert(mix64(0));
            sum = 0;
        }
        else
        {
            st.insert(mix64(sum));
        }
    }
    cout << ans << '\n';
}