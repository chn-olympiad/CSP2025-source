#include <bits/stdc++.h>
#define int long long
using namespace std;

int t;
int n;


struct Node
{
    pair<int, int> b[5];
    int max, min, dis;
    bool operator<(const Node& qwq)const
    {
        return dis > qwq.dis;
    }
} a[100005];



void solve()
{
    priority_queue<Node> q[5];
    int ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i].b[1].first >> a[i].b[2].first >> a[i].b[3].first,
        a[i].b[1].second = 1,
        a[i].b[2].second = 2,
        a[i].b[3].second = 3,
        sort(a[i].b + 1, a[i].b + 3 + 1),
        a[i].dis = a[i].b[3].first - a[i].b[2].first;
    
    for(int i = 1; i <= n; i++)
    {
        q[a[i].b[3].second].push(a[i]);
        ans += a[i].b[3].first;
    }

    if(q[1].size() > n / 2)
    {
        int tmp = q[1].size() - n / 2;
        while(tmp--)
        {
            //cout << q[1].top().dis << '\n';
            ans -= q[1].top().dis;
            q[1].pop();
        }
    }

    else if(q[2].size() > n / 2)
    {
        int tmp = q[2].size() - n / 2;
        //cout << '*' << q[2].size() << '\n';
        while(tmp--)
        {
            //cout << '*' << tmp << '\n';
            ans -= q[2].top().dis;
            q[2].pop();
        }
    }

    else if(q[3].size() > n / 2)
    {
        int tmp = q[3].size() - n / 2;
        while(tmp--)
        {
            ans -= q[3].top().dis;
            q[3].pop();
        }
    }

    cout << ans << '\n';

}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;

    while(t--) solve();

    return 0;
}