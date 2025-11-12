#include <bits/stdc++.h>
using namespace std;
long long n, k, maxn = LLONG_MIN;
vector<long long> a, s;
vector<pair<long long, long long>> book;
vector<bool> vis;
void dfs(long long sum, long long last)
{
    maxn = max(maxn, sum);
    for (long long i = 0; i < book.size(); ++i)
    {
        if (!vis[i] && book[i].first > last)
        {
            vis[i] = true;
            dfs(sum + 1, book[i].second);
            vis[i] = false;
        }
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    a.resize(n + 5);
    s.resize(n + 5, 0);
    for (long long i = 1; i <= n; ++i)
    {
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
    }
    // cout<<endl;
    // for (long long i = 1; i <= n; ++i)
    // {
    //     cout << s[i] << " ";
    // }
    // cout << endl;
    for (long long i = 1; i <= n; ++i)
    {
        for (long long j = i; j <= n; ++j)
        {
            if (i == j)
            {
                if (k == a[i])
                {
                    book.push_back({i, j});
                }
            }
            else
            {
                long long t = (s[j] ^ s[i - 1]);
                if (t == k)
                    book.push_back({i, j});
            }
        }
    }
    // for (long long i = 0; i < book.size(); ++i)
    // {
    //     cout << book[i].first << " " << book[i].second << "\n";
    // }
    // cout << endl;
    vis.resize(book.size() + 5, false);
    // cout<<11111<<endl;
    dfs(0, -1);
    cout << maxn;
    return 0;
}