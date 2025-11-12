#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int t[5], n;
struct node1
{
    int v, p;
};
struct node2
{
    node1 v[5];
} a[N];

bool cmp(node x, node y)
{
    return x.v[1].v - x.v[2].v > y.v[1].v - y.v[2].v;
}

void S(int x)
{
    if(a[x].v[2].v < a[x].v[3].v) swap(a[x].v[2], a[x].v[3]);
    if(a[x].v[1].v < a[x].v[2].v) swap(a[x].v[1], a[x].v[2]);
    if(a[x].v[2].v < a[x].v[3].v) swap(a[x].v[2], a[x].v[3]);
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T; cin >> T;
    while(T--)
    {
        memset(t, 0, sizeof t);
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= 3; j++)
            {
                cin >> a[i].v[j].v;
                a[i].v[j].p = j;
            }
            S(i);
        }
        sort(a + 1, a + n + 1, cmp);
        long long ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(t[a[i].v[1].p] < n / 2)
            {
                t[a[i].v[1].p]++;
                ans += a[i].v[1].v;
            }
            else ans += a[i].v[2].v;
        }
        cout << ans << endl;
    }
    return 0;
}
