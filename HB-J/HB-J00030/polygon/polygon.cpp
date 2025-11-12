#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

const int mod = 998244353;

struct node
{
    long long val, dep, sum;
};

long long n, a[N], prefix[N], res = 0;


void bfs()
{
    queue<node> q;
    for(long long i = 1;i <= n;++ i)
    {
        q.push({a[i], i, 1});
    }
    while(q.size())
    {
        node now = q.front();
        q.pop();
        if(now.dep == n)
        {
            continue;
        }
        if(now.sum > 1)
        {
            for(long long i = now.dep + 1;i <= n;++ i)
            {
                if(now.val > a[i])
                {
                    prefix[i] ++;
                    prefix[i] %= mod;
                }
                else
                {
                    break;
                }
            }
        }
        for(long long i = now.dep + 1;i <= n;++ i)
        {
            q.push({now.val + a[i], i, now.sum + 1});
        }
    }
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;

    for(long long i = 1;i <= n;++ i)
    {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);

    bfs();

    for(long long i = n;i >= 1;-- i)
    {
        prefix[i] += prefix[i + 1];
        prefix[i] %= mod;
    }

    cout << prefix[1];

    return 0;
}
