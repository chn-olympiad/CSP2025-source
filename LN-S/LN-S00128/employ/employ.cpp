#include<bits/stdc++.h>
using namespace std;

long long n , m;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n , &m);
    if(m == n)
    {
        long long l , ans = 1;
        string s;
        cin>>s;
        l = s.length();
        for(int i = 0 ; i < l ; i++)
        {
            if(s[i] == '0')
            {
                printf("0");
                return 0;
            }
        }
        for(int i = 1 ; i <= n ; i++)
        {
            ans *= i;
            ans = (ans + 998244353) % 998244353;
            long long x;
            scanf("%lld",&x);
            if(x == 0)
            {
                printf("0");
                return 0;
            }
        }
        printf("%lld",ans);
    }
    else if(m == 1)
    {
        long long r[505] , l , ans = 1 , ss[505] , cnt = 0;
        string s;
        cin>>s;
        l = s.length();
        for(int i = 0 ; i < l ; i++)
        {
            ss[i + 1] = s[i] - '0';
            if(ss[i + 1] == 1)
            {
                cnt++;
            }
        }
        if(cnt < m)
        {
            printf("0");
            return 0;
        }
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%lld",&r[i]);
        }
        sort(r + 1 , r + 1 + n);
        for(int i = 1 ; i <= n ; i++)
        {
            if(ss[i] == 1)
            {
                if(i - 1 < r[n])
                {
                    for(int j = 1 ; j <= n - i + 1 ; j++)
                    {
                        ans *= j;
                        ans = (ans + 998244353) % 998244353;
                    }
                    for(int j = 1 ; j <= n ; j++)
                    {
                        ans *= j;
                        ans = (ans + 998244353) % 998244353;
                    }
                    printf("%lld",ans);
                    return 0;
                }
                else
                {
                    for(int j = 1 ; j <= n ; j++)
                    {
                        ans *= j;
                        ans = (ans + 998244353) % 998244353;
                    }
                    printf("%lld\n",ans);
                }
            }
        }
    }
    else
    {
        bool b = true;
        long long r[505] , l , ans = 1 , ss[505] , cnt = 0;
        string s;
        cin>>s;
        l = s.length();
        for(int i = 0 ; i < l ; i++)
        {
            ss[i + 1] = s[i] - '0';
            if(ss[i + 1] == 1)
            {
                cnt++;
            }
        }
        if(cnt < m)
        {
            printf("0");
            return 0;
        }
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%lld",&r[i]);
            if(b && r[i] != 1)
            {
                b = !b;
            }
        }
        if(b)
        {
            for(int i = 1 ; i <= n ; i++)
            {
                if(ss[i] == 0)
                {
                    if(i < m)
                    {
                        printf("0");
                        return 0;
                    }
                    else
                    {
                        for(int j = 1 ; j <= n ; j++)
                        {
                            ans *= j;
                            ans = (ans + 998244353) % 998244353;
                        }
                        printf("%lld\n",ans);
                    }
                }
            }
        }

    }
    return 0;
}
