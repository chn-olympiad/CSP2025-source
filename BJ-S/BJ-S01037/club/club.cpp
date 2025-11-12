#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n;
struct node
{
    int a[4];
    int maxn , minn , mid;
};
node g[N];
bool cmp(node x , node y)
{
    if (x.maxn != y.maxn)
    {
        return x.maxn > y.maxn;
    }
    if (x.mid != y.mid)
    {
        return x.mid > y.mid;
    }
    return x.minn > y.minn;
}
void init()
{
    int hn = n / 2;
    int cnt1 = 0  , cnt2 = 0 , cnt3 = 0;
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        int mxn = g[i].maxn;
        int md = g[i].mid;
        int mnn = g[i].minn;
        if (mxn == g[i].a[1] && cnt1 < hn)
        {
            cnt1++;
            ans += mxn;
        }
        else if (mxn == g[i].a[2] && cnt2 < hn)
        {
            cnt2++;
            ans += mxn;
        }
        else if (mxn == g[i].a[3] && cnt3 < hn)
        {
            cnt3++;
            ans += mxn;
        }
        else if (mxn == g[i].a[1] && cnt1 >= hn)
        {
            if (md == g[i].a[2] && cnt2 < hn)
            {
                cnt2++;
                ans += md;
            }
            else
            {
                cnt3++;
                ans += md;
            }
        }
        else if (mxn == g[i].a[2] && cnt2 >= hn)
        {
            if (md == g[i].a[1] && cnt1 < hn)
            {
                cnt1++;
                ans += md;
            }
            else
            {
                cnt3++;
                ans += md;
            }
        }
        else
        {
            if (md == g[i].a[1] && cnt1 < hn)
            {
                cnt1++;
                ans += md;
            }
            else
            {
                cnt2++;
                ans += md;
            }
        }
    }
    cout << ans << endl;
}
vector<node> v[4];
void calc()
{
    for (int i = 1 ; i <= 3 ; i++)
    {
        v[i].clear();
    }
    int hn = n / 2;
    int cnt1 = 0  , cnt2 = 0 , cnt3 = 0;
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        int mxn = g[i].maxn;
        int md = g[i].mid;
        int mnn = g[i].minn;
        if (mxn == g[i].a[1] && cnt1 < hn)
        {
            cnt1++;
            ans += mxn;
            v[1].push_back(g[i]);
        }
        else if (mxn == g[i].a[2] && cnt2 < hn)
        {
            cnt2++;
            ans += mxn;
            v[2].push_back(g[i]);
        }
        else if (mxn == g[i].a[3] && cnt3 < hn)
        {
            cnt3++;
            ans += mxn;
            v[3].push_back(g[i]);
        }
        else if (mxn == g[i].a[1] && cnt1 >= hn)
        {
            bool lsf = 0;
            int cnt = 0;
            for (auto j : v[1])
            {
                if (j.maxn - j.mid <= mxn)
                {
                    ans -= j.maxn;
                    ans += j.mid;
                    if (j.mid == j.a[2])
                    {
                        cnt2++;
                        v[2].push_back(j);
                    }
                    else
                    {
                        cnt3++;
                        v[3].push_back(j);
                    }
                    v[1][cnt++] = g[i];
                    ans += mxn;
                    lsf = 1;
                    break;
                }
            }
            if (!lsf)
            {
                if (md == g[i].a[2])
                {
                    cnt2++;
                    ans += md;
                    v[2].push_back(g[i]);
                }
                else
                {
                    cnt3++;
                    ans += md;
                    v[3].push_back(g[i]);
                }
            }
        }
        else if (mxn == g[i].a[2] && cnt2 >= hn)
        {
            bool lsf = 0;
            int cnt = 0;
            for (auto j : v[2])
            {
                if (j.maxn - j.mid <= mxn)
                {
                    ans -= j.maxn;
                    ans += j.mid;
                    if (j.mid == j.a[1])
                    {
                        cnt1++;
                        v[1].push_back(j);
                    }
                    else
                    {
                        cnt3++;
                        v[3].push_back(j);
                    }
                    v[2][cnt++] = g[i];
                    ans += mxn;
                    lsf = 1;
                    break;
                }
            }
            if (!lsf)
            {
                if (md == g[i].a[1])
                {
                    cnt1++;
                    ans += md;
                    v[1].push_back(g[i]);
                }
                else
                {
                    cnt3++;
                    ans += md;
                    v[3].push_back(g[i]);
                }
            }
        }
        else
        {
            bool lsf = 0;
            int cnt = 0;
            for (auto j : v[3])
            {
                if (j.maxn - j.mid <= mxn)
                {
                    ans -= j.maxn;
                    ans += j.mid;
                    if (j.mid == j.a[1])
                    {
                        cnt1++;
                        v[1].push_back(j);
                    }
                    else
                    {
                        cnt2++;
                        v[2].push_back(j);
                    }
                    v[3][cnt++] = g[i];
                    ans += mxn;
                    lsf = 1;
                    break;
                }
            }
            if (!lsf)
            {
                if (md == g[i].a[1])
                {
                    cnt1++;
                    ans += md;
                    v[1].push_back(g[i]);
                }
                else
                {
                    cnt2++;
                    ans += md;
                    v[2].push_back(g[i]);
                }
            }
        }
    }
    cout << ans << endl;
}
void cf2()
{
    int ans = 0;
    int hn = n / 2;
    int cnt1 = 0 , cnt2 = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        int mxn = g[i].maxn;
        int md = g[i].mid;
        int mnn = g[i].minn;
        if (mxn == g[i].a[1] && cnt1 < hn)
        {
            cnt1++;
            v[1].push_back(g[i]);
        }
        else if (mxn = g[i].a[2] && cnt2 < hn)
        {
            cnt2++;
            v[2].push_back(g[i]);
        }
        else if (cnt1 < hn)
        {
            bool lsf = 1;
            for (int j = 0 ; j < v[1].size() ; j++)
            {
                node t = v[1][j];
                if (t.maxn - t.mid <= mxn)
                {
                    v[1][j] = g[i];
                    ans -= t.maxn;
                    ans += t.mid;
                    ans += mxn;
                    cnt2++;
                    v[2].push_back(t);
                    lsf = 0;
                    break;
                }
            }
            if (lsf)
            {
                ans += md;
                cnt2++;
                v[2].push_back(g[i]);
            }
        }
        else
        {
            bool lsf = 1;
            for (int j = 0 ; j < v[2].size() ; j++)
            {
                node t = v[2][j];
                if (t.maxn - t.mid <= mxn)
                {
                    v[2][j] = g[i];
                    ans -= t.maxn;
                    ans += t.mid;
                    ans += mxn;
                    cnt1++;
                    v[1].push_back(t);
                    lsf = 0;
                    break;
                }
            }
            if (lsf)
            {
                ans += md;
                cnt1++;
                v[1].push_back(g[i]);
            }
        }
    }
    cout << ans << endl;
}
signed main()
{
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        bool f1 = 1 , f2 = 1;
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> g[i].a[1] >> g[i].a[2] >> g[i].a[3];
            if (g[i].a[3] != 0 || g[i].a[2] != 0)
            {
                f1 = 0;
            }
            if (g[i].a[3] != 0)
            {
                f2 = 0;
            }
            g[i].maxn = max({g[i].a[1] , g[i].a[2] , g[i].a[3]});
            g[i].minn = min({g[i].a[1] , g[i].a[2] , g[i].a[3]});
            g[i].mid = g[i].a[1] + g[i].a[2] + g[i].a[3] - g[i].maxn - g[i].minn;
        }
        sort(g + 1 , g + n + 1 , cmp);
        if (f1)
        {
            int ans = 0;
            int hn = n / 2;
            for (int i = 1 ; i <= hn ; i++)
            {
                ans += g[i].a[1];
            }
            cout << ans << endl;
        }
        else if (n <= 200)
        {
            calc();
        }
        else if (f2)
        {
            cf2();
        }
        else
        {
            init();
        }
    }
    return 0;
}