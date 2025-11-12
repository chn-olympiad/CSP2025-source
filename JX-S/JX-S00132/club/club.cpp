#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

struct info
{
    int a;
    int b;
    int c;
};

long long ans = 0;

int cnta, cntb, cntc;
int n, t;
vector<info> depart;

bool cmp(info a, info b)
{
    return a.a > b.a;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--)
    {
        depart = vector<info>();
        cin >> n;
        for (int i = 0, a, b, c; i < n; ++i)
        {
            cin >> a >> b >> c;
            depart.push_back({a, b, c});
        }

        sort(depart.begin(), depart.end(), cmp);
        for (int i = 0; i < n / 2; ++i)
        {
            ans += depart[i].a;
        }
        cout << ans << "\n";
    }

    return 0;
}
