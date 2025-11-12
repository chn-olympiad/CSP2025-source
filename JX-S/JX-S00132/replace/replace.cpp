#include <bits/stdc++.h>
using namespace std;

long long ans = 0;
int n, q;
vector<pair<string, string>> act;

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    string a, b;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        act.push_back({a, b});
    }
    while (q--)
    {
        cin >> a >> b;
        for (int i = 0; i < n; ++i)
        {
            long long idx = 0;
            if (a.find(act[i].first) != string::npos)
            {
                for (int i = 0; i <= a.size() - act[i].first.size(); ++i)
                {
                    idx = a.find(act[i].first, i);
                    cout << idx << endl;
                    for (int i = 0; i < act[i].second.size(); ++i)
                    {
                        a[i + idx] = act[i].second[i];
                    }
                    if (a == b)
                    {
                        ans++;
                    }
                }
            }
        }
        cout << ans;
    }

    return 0;
}
