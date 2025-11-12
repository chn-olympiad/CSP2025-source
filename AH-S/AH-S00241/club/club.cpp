#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
bool flagA = 1;
int n, t, maxn;
long long ans;
struct memb
{
    long long x, y, z, bst;
}a[N];
bool cmpa(memb aa, memb bb)
{
    return aa.x > bb.x;
}
map<int, int> mp1, mp2, mp3;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        mp1.clear();
        mp2.clear();
        mp3.clear();
        ans = 0;
        cin >> n;
        maxn = n/2;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].x>>a[i].y>>a[i].z;
            if (a[i].x > a[i].y && a[i].x > a[i].z) a[i].bst = 1;
            else if (a[i].y > a[i].x && a[i].y > a[i].z) a[i].bst = 2;
            else a[i].bst = 3;
            if (a[i].y != 0 || a[i].z != 0)
            {
                flagA = 0;
            }
        }
        if (flagA)
        {
            sort(a+1, a+n+1, cmpa);
            for (int i = 1; i <= maxn; i++)
            {
                ans += a[i].x;
            }
            cout << ans << "\n";
        }
        else if (n == 2)
        {
            int ans1 = a[1].x + max(a[2].y, a[2].z);
            int ans2 = a[1].y + max(a[2].x, a[2].z);
            int ans3 = a[1].z + max(a[2].x, a[2].y);
            ans = max(ans1, max(ans2, ans3));
            cout << ans << "\n";
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (a[i].bst == 1)
                {
                    if (mp1.size() < maxn)
                    {
                        mp1[i] = a[i].x;
                    }
                    else
                    {
                        if (a[i].y>a[i].z)
                        {
                            a[i].bst = 2;
                        }
                        else
                        {
                            a[i].bst = 3;
                        }
                    }
                }
                if (a[i].bst == 2)
                {
                    if (mp2.size() < maxn)
                    {
                        mp2[i] = a[i].y;
                    }
                    else
                    {
                        if (a[i].x>a[i].z && mp1.size()<maxn)
                        {
                            a[i].bst = 1;
                            mp1[i] = a[i].x;
                        }
                        else
                        {
                            a[i].bst = 3;
                        }
                    }
                }
                if (a[i].bst == 3)
                {
                    if (mp3.size() < maxn)
                    {
                        mp3[i] = a[i].z;
                    }
                    else
                    {
                        if (a[i].x>a[i].y && mp1.size()<maxn)
                        {
                            a[i].bst = 1;
                            mp1[i] = a[i].x;
                        }
                        else if (a[i].y>a[i].x && mp2.size()<maxn)
                        {
                            a[i].bst = 2;
                            mp2[i] = a[i].y;
                        }
                        auto tp1 = mp1.begin();
                        auto tp2 = mp2.begin();
                        auto tp3 = mp3.begin();
                        if ((tp1->second < a[i].x) && (mp1.size()==maxn))
                        {
                            mp1.erase(tp1);
                            mp1[i] = a[i].x;
                        }
                        else if ((tp2->second < a[i].y) && (mp2.size()==maxn))
                        {
                            mp2.erase(tp2);
                            mp2[i] = a[i].y;
                        }
                        else if ((tp3->second < a[i].z) && (mp3.size()==maxn))
                        {
                            mp3.erase(tp3);
                            mp3[i] = a[i].z;
                        }
                    }
                }
            }
            for (auto &i:mp1)
            {
                ans += i.second;
            }
            for (auto &i:mp2)
            {
                ans += i.second;
            }
            for (auto &i:mp3)
            {
                ans += i.second;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
