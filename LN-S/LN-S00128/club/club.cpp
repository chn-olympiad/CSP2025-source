#include<bits/stdc++.h>
using namespace std;

struct node
{
    long long a;
    long long b;
    long long c;
};

long long T;

long long cmp1(long long a , long long b)
{
    return a < b;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&T);
    while(T--)
    {
        node r[100005] = { };
        long long n , ans = 0 , aa = 0 , bb = 0 , cc = 0 , a[100005] = { } ,  b[100005] = { } , c[100005] = { };
        scanf("%lld",&n);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%lld%lld%lld",&r[i].a , &r[i].b , &r[i].c);
            if(r[i].a >= max(r[i].b , r[i].c))
            {
                ans += r[i].a;
                aa++;
                a[aa] = min(r[i].a - r[i].b , r[i].a - r[i].c);
            }
            else if(r[i].b >= max(r[i].a , r[i].c))
            {
                ans += r[i].b;
                bb++;
                b[bb] = min(r[i].b - r[i].a , r[i].b - r[i].c);
            }
            else
            {
                ans += r[i].c;
                cc++;
                c[cc] = min(r[i].c - r[i].b , r[i].c - r[i].a);
            }
        }
        if(aa * 2 <= n && bb * 2 <= n && cc * 2 <= n)
        {
            printf("%lld\n",ans);
        }
        else
        {
            if(aa * 2 > n)
            {
                sort(a + 1 , a + aa + 1 , cmp1);
                for(int i = 1 ; i <= aa - n / 2 ; i++)
                {
                    ans -= a[i];
                }
            }
            else if(bb * 2 > n)
            {
                sort(b + 1 , b + bb + 1 , cmp1);
                for(int i = 1 ; i <= bb - n / 2 ; i++)
                {
                    ans -= b[i];
                }
            }
            else
            {
                sort(c + 1 , c + cc + 1 , cmp1);
                for(int i = 1 ; i <= cc - n / 2 ; i++)
                {
                    ans -= c[i];
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
