#include <bits/stdc++.h>
using namespace std;

struct node
{
    int n[4];
};
struct node2
{
    int n, id;
};
bool cmp(node x, node y)
{
    sort(x.n+1, x.n+4);
    sort(y.n+1, y.n+4);
    if(x.n[3] != y.n[3])
        return x.n[3] > y.n[3];
    if(x.n[2] != y.n[2])
        return x.n[2] > y.n[2];
    return x.n[1] > y.n[1];
}
bool cmp2(node2 x, node2 y)
{
    return x.n > y.n;
}

void calc()
{
    int n;
    cin >> n;
    node a[100010];
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d%d", &a[i].n[1], &a[i].n[2], &a[i].n[3]);
        int minn = min({a[i].n[1], a[i].n[2], a[i].n[3]});
        a[i].n[1] -= minn;
        a[i].n[2] -= minn;
        a[i].n[3] -= minn;
        ans += minn;
    }
    sort(a+1, a+n+1, cmp);
    int cnt[4] = {0};
    for(int i=1; i<=n; i++)
    {
        node2 b[4];
        b[1].n = a[i].n[1];
        b[2].n = a[i].n[2];
        b[3].n = a[i].n[3];
        b[1].id = 1;
        b[2].id = 2;
        b[3].id = 3;
        sort(b+1, b+4, cmp2);
        if(b[1].n == b[2].n)
            ans += b[1].n;
        else if(cnt[b[1].id] < n/2)
        {
            ans += b[1].n;
            cnt[b[1].id]++;
        }
        else if(b[2].n == b[3].n)
            ans += b[2].n;
        else
        {
            ans += b[2].n;
            cnt[b[2].id]++;
        }
    }
    cout << ans << endl;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >>t;
    while(t--)
    {
        calc();
    }
    return 0;
}
