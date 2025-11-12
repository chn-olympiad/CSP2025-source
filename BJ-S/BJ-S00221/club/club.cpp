#include <bits/stdc++.h>
using namespace std;

struct node
{
    int f1, f2, f3, id1, id2, id3, jump = 0;
}a[100010];

bool cmp(node x, node y)
{
    if (x.f1 != y.f1) return x.f1 > y.f1;
    else if(x.f2 != y.f2) return x.f2 > y.f2;
    return x.f3 > y.f3;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        long long n, ans = 0, cnt[5] = {0};
        cin >> n;
        memset(a, sizeof(a), 0);
        for (int i = 1; i <= n; i++)
        {
            int b, c, d;
            cin >> b >> c >> d;
            if(max(b, max(c, d)) == b)
            {
                a[i].f1 = b;
                a[i].id1 = 1;
                if (c > d)
                {
                    a[i].f2 = c;
                    a[i].id2 = 2;
                    a[i].f3 = d;
                    a[i].id3 = 3;
                }
                else
                {
                    a[i].f2 = d;
                    a[i].id2 = 3;
                    a[i].f3 = c;
                    a[i].id3 = 2;
                }
            }
            else if (max(b, max(c, d)) == c)
            {
                a[i].f1 = c;
                a[i].id1 = 2;
                if (b > d)
                {
                    a[i].f2 = b;
                    a[i].id2 = 1;
                    a[i].f3 = d;
                    a[i].id3 = 3;
                }
                else
                {
                    a[i].f2 = d;
                    a[i].id2 = 3;
                    a[i].f3 = b;
                    a[i].id3 = 1;
                }
            }
            else
            {
                a[i].f1 = d;
                a[i].id1 = 3;
                if (b > c)
                {
                    a[i].f2 = b;
                    a[i].id2 = 1;
                    a[i].f3 = c;
                    a[i].id3 = 2;
                }
                else
                {
                    a[i].f2 = c;
                    a[i].id2 = 2;
                    a[i].f3 = b;
                    a[i].id3 = 1;
                }
            }
        }
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; i++)
        {

            if (a[i].jump == 1)
            {
                continue;
            }
            if (cnt[a[i].id1] < n / 2)
            {
                cnt[a[i].id1]++;
                ans += a[i].f1;
                //cout << a[i].f1 << " " << a[i].f2 << " " << a[i].f3 << endl;
                //cout << "c1:" << cnt[1] << " 2:" << cnt[2] << " 3:" << cnt[3] << " ans:" << ans << endl;
            }
            else if (cnt[a[i].id2] < n / 2)
            {
                bool flag = false;
                long long maxn = 0, maxi = 0;
                for (int j = 1; j <= i - 1; j++)
                {
                    if (a[i].id1 == a[j].id1 && a[j].jump != 1 && maxn < a[j].f2 + a[i].f1 - a[j].f1)
                    {
                        maxn = a[j].f2 + a[i].f1 - a[j].f1;
                        maxi = j;
                    }
                }

                cnt[a[i].id1]++;
                cnt[a[maxi].id1]--;
                cnt[a[maxi].id2]++;
                ans -= a[maxi].f1;
                ans += a[maxi].f2 + a[i].f1;
                //cout << maxi << " " << a[i].f1 << " " << a[i].f2 << " " << a[i].f3 << endl;
                //cout << a[maxi].f1 << " " << a[maxi].f2 << " " << a[maxi].f3 << endl;
                //cout << "a1:" << cnt[1] << " 2:" << cnt[2] << " 3:" << cnt[3] << " ans:" << ans << endl;
                a[maxi].jump = 1;
                a[i].jump = 1;
                continue;
            }
            else
            {
                ans += a[i].f3;
                cnt[a[i].id3]++;
                //cout << a[i].f1 << " " << a[i].f2 << " " << a[i].f3 << endl;
                //cout << "f1:" << cnt[1] << " 2:" << cnt[2] << " 3:" << cnt[3] << " ans:" << ans << endl;
            }
        }
        for (int i = 1; i <=  n; i++) a[i].jump = 0;
        cout << ans << endl;
    }
    return 0;
}
