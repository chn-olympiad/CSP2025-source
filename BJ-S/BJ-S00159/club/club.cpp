#include <bits/stdc++.h>
using namespace std;
long long n,t;
struct T
{
    long long a,b,c,d,q;
};
T a[1000005];
bool cmp1(T q1,T w1)
{
    return q1.a > w1.a;
}
bool cmp2(T q1,T w1)
{
    return q1.b > w1.b;
}
bool cmp3(T q1,T w1)
{
    return q1.c > w1.c;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1;i <= n;i++)
        {
            a[i].d = -1;
            a[i].q = 0;
        }
        for (int i = 1;i <= n;i++)
        {
            cin >> a[i].a >> a[i].b >> a[i].c;
            a[i].d = max(a[i].a,max(a[i].b,a[i].c));
        }
        sort(a+1,a+1+n,cmp1);
        long long suma = 0,ans = 0;
        for (int i = 1;i <= n;i++)
        {
            if (a[i].d==a[i].a && suma+1 <= n/2)
            {
                suma++;
                ans+=a[i].a;
                a[i].q=1;
            }
        }
        sort(a+1,a+1+n,cmp2);
        long long sumb = 0;
        for (int i = 1;i <= n;i++)
        {
            if (a[i].d==a[i].b && sumb+1 <= n/2 && a[i].q!=1)
            {
                sumb++;
                ans+=a[i].b;
                a[i].q=1;
            }
        }
        sort(a+1,a+1+n,cmp3);
        long long sumc = 0;
        for (int i = 1;i <= n;i++)
        {
            if (a[i].d==a[i].c && sumc+1 <= n/2 && a[i].q!=1)
            {
                sumc++;
                ans+=a[i].c;
                a[i].q=1;
            }
        }
        for (int i = 1;i <= n;i++)
        {
            if (a[i].q==0)
            {
                if (suma > n/2)
                {
                    ans+=max(a[i].b,a[i].c);
                }
                else if(sumb > n/2)
                {
                    ans+=max(a[i].a,a[i].c);
                }
                else if (sumc > n/2)
                {
                    ans+=max(a[i].a,a[i].b);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
