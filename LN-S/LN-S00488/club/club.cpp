#include <bits/stdc++.h>

using namespace std;

struct node
{
    int a , b , c;
} a[100010] , aa[100010] , bb[100010] , cc[100010];

bool cmp(node x , node y)
{
    return max(x.a , max(x.b , x.c)) > max(y.a , max(y.b , y.c));
}

bool cmp1(node x , node y)
{
    return x.a - max(x.b , x.c) < y.a - max(y.b , y.c);
}

bool cmp2(node x , node y)
{
    return x.b - max(x.a , x.c) < y.b - max(y.a , y.c);
}

bool cmp3(node x , node y)
{
    return x.c - max(x.a , x.b) < y.c - max(y.a , y.b);
}


int main()
{
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T --)
    {
        long long n , sum1 = 0 , sum2 = 0 , sum3 = 0 , ans = 0;
        cin >> n;
        for(int i = 1; i <= n; ++ i) cin >> a[i].a >> a[i].b >> a[i].c;
        sort(a + 1 , a + n + 1 , cmp);
        for(int i = 1; i <= n; ++ i)
        {
            if(max(max(a[i].a , a[i].b) , a[i].c) == a[i].a)
            {
                sum1 ++;
                ans += a[i].a;
                aa[sum1] = a[i];
            }
            else if(max(max(a[i].a , a[i].b) , a[i].c) == a[i].b)
            {
                sum2 ++;
                ans += a[i].b;
                bb[sum2] = a[i];
            }
            else if(max(max(a[i].a , a[i].b) , a[i].c) == a[i].c)
            {
                sum3 ++;
                ans += a[i].c;
                cc[sum3] = a[i];
            }
        }
        if(sum1 > n / 2)
        {
            sort(aa + 1 , aa + sum1 + 1 , cmp1);
            sum1 -= n / 2;
            for(int i = 1; i <= sum1; ++ i)
            {
                ans -= aa[i].a - max(aa[i].b , aa[i].c);
            }
        }
        else if(sum2 > n / 2)
        {
            sort(bb + 1 , bb + sum2 + 1 , cmp2);
            sum2 -= n / 2;
            for(int i = 1; i <= sum2; ++ i)
            {
                ans -= bb[i].b - max(bb[i].a , bb[i].c);
            }
        }
        else if(sum3 > n / 2)
        {
            sort(cc + 1 , cc + sum3 + 1 , cmp3);
            sum3 -= n / 2;
            for(int i = 1; i <= sum3; ++ i)
            {
                ans -= cc[i].c - max(cc[i].a , cc[i].b);
            }

        }
        cout << ans << '\n';
    }
    return 0;
}