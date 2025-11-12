#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int gt, mon;
};
vector<Node> v[10010];
int a[10010][5010], cur[10010];
bool flag[10010];
long long n, m, k, minn;

bool check()
{
    queue<int> q;
    memset(flag, 0, sizeof flag);
    q.push(1);
    flag[1] = 1;
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        for(auto i : a[top])
        {
            if(!flag[i])
            {
                flag[i] = 1;
                q.push(i);
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(!flag[i])
        {
            return 0;
        }
    }
    return 1;
}

void dfs(int step, long long sum)
{
    if(step > n)
    {
        if(check())
        {
            minn = min(minn, sum);
        }
        return;
    }
    if(sum > minn) return;
    dfs(step + 1, sum);
    for(auto i : v[step])
    {
        a[step][++cur[step]] = i.gt;
        a[i.gt][++cur[i.gt]] = step;
        dfs(step + 1, sum + i.mon);
        a[step][cur[step]--] = 0;
        a[i.gt][cur[i.gt]--] = 0;
    }
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    minn = 10000000000000000;
    cin >> n >> m >> k;
    if(k == 0)
    {
        for(int i = 1; i <= n; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            v[a].push_back({b, c});
            v[b].push_back({a, c});
        }
        dfs(1, 0);
        cout << minn << endl;
    }
    else cout << 0 << endl;
    return 0;
}
