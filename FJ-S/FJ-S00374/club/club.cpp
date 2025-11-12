#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+5;
int n, a[N][3], k, t, cnt, mx;
ll ans;
struct Node
{
    int a, b, d;

    bool operator < (const Node &A) const
    {
        return d > A.d;
    }
}x[N];

bool cmp(Node x, Node y)
{
    return x.a > y.a;
}

int f(int _)
{
    return (mx+1+_)%3+1;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n; k = n/2;
        for(int i = 1, p[] = {0, 0, 0, 0}; i <= n; i++)
        {
            scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
            if(a[i][1] == max({a[i][1], a[i][2], a[i][3]})) p[1]++;
            else if(a[i][2] == max({a[i][1], a[i][2], a[i][3]})) p[2]++;
            else p[3]++;
            if(p[1] > p[mx]) mx = 1;
            if(p[2] > p[mx]) mx = 2;
            if(p[3] > p[mx]) mx = 3;
        }
        cnt = ans = 0;
        priority_queue<Node> q;
        for(int i = 1; i <= n; i++)
        {
            ans += a[i][f(3)];
            int a1 = a[i][f(1)]-a[i][f(3)], a2 = a[i][f(2)]-a[i][f(3)];
            x[i] = {a1, a2, a1-a2};
        }
        sort(x+1, x+n+1, cmp);
        for(int i = 1; i <= n; i++)
        {
            int a1 = x[i].a, a2 = x[i].b, d = x[i].d;
            if(a2 > a1 && a2 > 0)
            {
                ans += a2;
                continue;
            }
            if(a1 <= 0 && a2 <= 0) continue;
            if(cnt < k)
            {
                cnt++, q.push(x[i]);
                ans += a1;
                continue;
            }
            if(d > q.top().d && a1-q.top().d > 0)
            {
                ans += a1-q.top().d;
                q.pop();
                q.push(x[i]);
            }
            else if(a2 > 0)
            {
                ans += a2;
                continue;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}