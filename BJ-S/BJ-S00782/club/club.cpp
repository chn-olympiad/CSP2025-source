#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int T,n,cnta,cntb,cntc;
long long ans;
struct stu{
    int a,b,c,v,m;
}s[500005];
bool cmp(stu x,stu y)
{
    if (x.m != y.m) return x.m < y.m;
    return x.v < y.v;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while (T--)
    {
        cin >> n;
        ans = 0;
        cnta = 0;
        cntb = 0;
        cntc = 0;
        for (int i = 1;i <= n;i++)
        {
            cin >> s[i].a >> s[i].b >> s[i].c;
            if (s[i].a >= s[i].b && s[i].a >= s[i].c)
            {
                s[i].m = 1;
                s[i].v = min(s[i].b,s[i].c) + s[i].a - s[i].b - s[i].c;
                cnta++;
                ans += s[i].a;
            }
            else if (s[i].b >= s[i].a && s[i].b >= s[i].c)
            {
                s[i].m = 2;
                s[i].v = min(s[i].a,s[i].c) - s[i].a + s[i].b - s[i].c;
                cntb++;
                ans += s[i].b;
            }
            else
            {
                s[i].m = 3;
                s[i].v = min(s[i].a,s[i].b) - s[i].a - s[i].b + s[i].c;
                cntc++;
                ans += s[i].c;
            }
        }
        sort(s + 1,s + n + 1,cmp);
        if (cnta > n / 2)
        {
            for (int i = 1;i <= cnta - n / 2;i++)
            {
                ans -= s[i].v;
            }
        }
        else if (cntb > n / 2)
        {
            for (int i = cnta + 1;i <= cnta + cntb - n / 2;i++)
            {
                ans -= s[i].v;
            }
        }
        else if (cntc > n / 2)
        {
            for (int i = cnta + cntb + 1;i <= n / 2;i++)
            {
                ans -= s[i].v;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
