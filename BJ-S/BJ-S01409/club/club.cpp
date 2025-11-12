#include<bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int t, n, ans, a[100005][5];
list<int> b[5];

struct node
{
    int c, v;
    list<int>::iterator it;
};

bool operator< (node x, node y)
{
    return x.v < y.v;
}

int cal1(int c)
{
    int v = INT_MIN;
    if(b[2].size() + 1 <= n / 2)
    {
        v = max(v, a[c][2]);
    }
    if(b[3].size() + 1 <= n / 2)
    {
        v = max(v, a[c][3]);
    }
    return v;
}

int cal2(int c)
{
    int v = INT_MIN;
    if(b[1].size() + 1 <= n / 2)
    {
        v = max(v, a[c][1]);
    }
    if(b[3].size() + 1 <= n / 2)
    {
        v = max(v, a[c][3]);
    }
    return v;
}

int cal3(int c)
{
    int v = INT_MIN;
    if(b[1].size() + 1 <= n / 2)
    {
        v = max(v, a[c][1]);
    }
    if(b[2].size() + 1 <= n / 2)
    {
        v = max(v, a[c][2]);
    }
    return v;
}

void solve()
{
    ans = 0;
    cin >> n;
    // cout << endl;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
        {
            b[1].push_back(i);
            ans += a[i][1];
        }
        else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
        {
            b[2].push_back(i);
            ans += a[i][2];
        }
        else if(a[i][3] >= a[i][1] && a[i][3] >= a[i][2])
        {
            b[3].push_back(i);
            ans += a[i][3];
        }
    }

    // cout << "b1: ";
    // for(auto c : b[1])
    // {
    //     cout << c << " ";
    // }
    // cout << endl;
    // cout << "b2: ";
    // for(auto c : b[2])
    // {
    //     cout << c << " ";
    // }
    // cout << endl;
    // cout << "b3: ";
    // for(auto c : b[3])
    // {
    //     cout << c << " ";
    // }
    // cout << endl;

    // b1
    if(b[1].size() > n / 2)
    {
        // cout << "b1\n";
        multiset<node> k;
        for(auto it = b[1].begin(); it != b[1].end(); it++)
        {
            int c = *it;
            if(cal1(c) == INT_MIN)
            {
                continue;
            }
            k.insert({c, a[c][1] - cal1(c), it});
        }
        while(b[1].size() > n / 2)
        {
            int c = (k.begin())->c;
            int v = (k.begin())->v;
            auto it = (k.begin())->it;
            it = b[1].erase(it);
            k.erase(k.begin());
            ans -= v;
            if(v == a[c][2] && b[2].size() + 1 <= n / 2)
            {
                b[2].push_back(c);
            }
            else
            {
                b[3].push_back(c);
            }
        }
    }

    // b2
    if(b[2].size() > n / 2)
    {
        // cout << "b2\n";
        multiset<node> k;
        for(auto it = b[2].begin(); it != b[2].end(); it++)
        {
            int c = *it;
            if(cal2(c) == INT_MIN)
            {
                continue;
            }
            k.insert({c, a[c][2] - cal2(c), it});
        }
        while(b[2].size() > n / 2)
        {
            int c = (k.begin())->c;
            int v = (k.begin())->v;
            auto it = (k.begin())->it;
            it = b[2].erase(it);
            k.erase(k.begin());
            ans -= v;
            if(v == a[c][1] && b[1].size() + 1 <= n / 2)
            {
                b[1].push_back(c);
            }
            else
            {
                b[3].push_back(c);
            }
        }
    }

    // b3
    if(b[3].size() > n / 2)
    {
        // cout << "b3\n";
        multiset<node> k;
        for(auto it = b[3].begin(); it != b[3].end(); it++)
        {
            int c = *it;
            if(cal3(c) == INT_MIN)
            {
                continue;
            }
            k.insert({c, a[c][3] - cal3(c), it});
        }
        // for(auto c : k)
        // {
        //     cout << "   " << c.c << ", " << c.v << endl;
        // }
        while(b[3].size() > n / 2)
        {
            int c = (k.begin())->c;
            int v = (k.begin())->v;
            auto it = (k.begin())->it;
            it = b[3].erase(it);
            k.erase(k.begin());
            // cout << "   c = " << c << ", v = " << v << endl;
            ans -= v;
            if(v == a[c][1] && b[1].size() + 1 <= n / 2)
            {
                b[1].push_back(c);
            }
            else
            {
                b[2].push_back(c);
            }
        }
    }
    cout << ans << endl;
    b[1].clear();
    b[2].clear();
    b[3].clear();
}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}

/*
CSP-S 2025 RP+=1e20
mengleo 872662
2025.10.30.
*/