#include <bits/stdc++.h>
using namespace std;

int t, n, l1[50005], l2[50005], l3[50005];
long long ans;

struct Node
{
    int a1, a2, a3, maxn;
}a[100005];

bool cmp1(int x, int y)
{
    return a[x].a1 - max(a[x].a2, a[x].a3) > a[y].a1 - max(a[y].a2, a[y].a3);
}

bool cmp2(int x, int y)
{
    return a[x].a2 - max(a[x].a1, a[x].a3) > a[y].a2 - max(a[y].a1, a[y].a3);
}

bool cmp3(int x, int y)
{
    return a[x].a3 - max(a[x].a2, a[x].a1) > a[y].a3 - max(a[y].a2, a[y].a1);
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(l1, 0, sizeof(l1));
        memset(l2, 0, sizeof(l2));
        memset(l3, 0, sizeof(l3));
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
            a[i].maxn = max({a[i].a1, a[i].a2, a[i].a3});
            if(a[i].maxn == a[i].a1) l1[++l1[0]] = i;
            else if(a[i].maxn == a[i].a2) l2[++l2[0]] = i;
            else if(a[i].maxn == a[i].a3) l2[++l2[0]] = i;
            ans += a[i].maxn;
        }
        while(l1[0] > (n/2) || l2[0] > (n/2) || l3[0] > (n/2))
        {
            if(l1[0] > (n/2))
            {
                sort(l1 + 1, l1 + l1[0] + 1, cmp1);
                while(l1[0] > (n/2))
                {
                    if(a[l1[l1[0]]].a2 >= a[l1[l1[0]]].a3)
                    {
                        ans -= a[l1[l1[0]]].a1 - a[l1[l1[0]]].a2;
                        l2[0]++;
                        l2[l2[0]] = l1[l1[0]];
                        l1[l1[0]] = 0;
                        l1[0]--;
                    }
                    else
                    {
                        ans -= a[l1[l1[0]]].a1 - a[l1[l1[0]]].a3;
                        l3[0]++;
                        l3[l3[0]] = l1[l1[0]];
                        l1[l1[0]] = 0;
                        l1[0]--;
                    }
                }
            }
            if(l2[0] > (n/2))
            {
                sort(l2 + 1, l2 + l2[0] + 1, cmp2);
                while(l2[0] > (n/2))
                {
                    if(a[l2[l2[0]]].a1 >= a[l2[l2[0]]].a3)
                    {
                        ans -= a[l2[l2[0]]].a2 - a[l2[l2[0]]].a1;
                        l1[0]++;
                        l1[l1[0]] = l2[l2[0]];
                        l2[l2[0]] = 0;
                        l2[0]--;
                    }
                    else
                    {
                        ans -= a[l2[l2[0]]].a2 - a[l2[l2[0]]].a3;
                        l3[0]++;
                        l3[l3[0]] = l1[l1[0]];
                        l2[l2[0]] = 0;
                        l2[0]--;
                    }
                }
            }
            if(l3[0] > (n/2))
            {
                sort(l3 + 1, l3 + l3[0] + 1, cmp3);
                while(l3[0] > (n/2))
                {
                    if(a[l3[l3[0]]].a1 >= a[l3[l3[0]]].a2)
                    {
                        ans -= a[l3[l3[0]]].a3 - a[l3[l3[0]]].a1;
                        l1[0]++;
                        l1[l1[0]] = l3[l3[0]];
                        l3[l3[0]] = 0;
                        l3[0]--;
                    }
                    else
                    {
                        ans -= a[l3[l3[0]]].a3 - a[l3[l3[0]]].a2;
                        l2[0]++;
                        l2[l2[0]] = l3[l3[0]];
                        l3[l3[0]] = 0;
                        l3[0]--;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
