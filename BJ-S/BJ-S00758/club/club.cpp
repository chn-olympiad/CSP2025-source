#include <bits/stdc++.h>
using namespace std ;
#define int long long
struct node 
{
    int a , b , c ;
}club[100050] ;
bool cmp(node x , node y)
{
    int cnt1 = abs(x.a - x.b) + abs(x.a - x.c) + abs(x.c - x.b) ;
    int cnt2 = abs(y.a - y.b) + abs(y.a - y.c) + abs(y.c - y.b) ;
    return cnt1 > cnt2 ;
}
signed main()
{
    freopen("club.in" , "r" , stdin) ;
    freopen("club.out" , "w" , stdout) ;
    int t ;
    cin >> t;
    while(t --)
    {
        int n ;
        cin >> n ;
        for(int i = 1 ; i <= n ; i ++)
        {
            cin >> club[i].a >> club[i].b >> club[i].c ;       
        }
        sort(club + 1 , club + n + 1 , cmp) ;
        int cnt1 = 0 , cnt2 = 0 , cnt3 = 0 , ans = 0;
        for(int i = 1 ; i <= n ; i ++)
        {
            int maxn = max(max(club[i].a , club[i].b) , club[i].c) ;
            if(maxn == club[i].a)
            {
                if(cnt1 < n / 2)
                {
                    cnt1 ++ ;
                    ans += maxn;
                }
                else 
                {
                    int maxn2 = max(club[i].b , club[i].c) ;
                    if(cnt2 < n / 2 && cnt3 < n / 2) 
                    {
                        if(maxn2 == club[i].b)
                        {
                            cnt2 ++ ;
                            ans += maxn2 ;
                        }
                        else if(maxn2 == club[i].c)
                        {
                            cnt3 ++ ;
                            ans += maxn2 ;
                        }
                    }
                    else if(cnt2 < n / 2 && cnt3 >= n / 2)
                    {
                        cnt2 ++ ;
                        ans += club[i].b;
                    }
                    else if(cnt3 < n / 2 && cnt2 >= n / 2)
                    {
                        cnt3 ++ ;
                        ans += club[i].c;
                    }
                }
            }
            if(maxn == club[i].b)
            {
                if(cnt2 < n / 2)
                {
                    cnt2 ++ ;
                    ans += maxn;
                }
                else 
                {
                    int maxn2 = max(club[i].a , club[i].c) ;
                    if(cnt1 < n / 2 && cnt3 < n / 2) 
                    {
                        if(maxn2 == club[i].a)
                        {
                            cnt1 ++ ;
                            ans += maxn2 ;
                        }
                        else if(maxn2 == club[i].c)
                        {
                            cnt3 ++ ;
                            ans += maxn2 ;
                        }
                    }
                    else if(cnt1 < n / 2 && cnt3 >= n / 2)
                    {
                        cnt1 ++ ;
                        ans += club[i].a;
                    }
                    else if(cnt1 < n / 2 && cnt3 >= n / 2)
                    {
                        cnt3 ++ ;
                        ans += club[i].c;
                    }
                }
            }
            if(maxn == club[i].c)
            {
                if(cnt3 < n / 2)
                {
                    cnt3 ++ ;
                    ans += maxn;
                }
                else 
                {
                    int maxn2 = max(club[i].b , club[i].a) ;
                    if(cnt2 < n / 2 && cnt1 < n / 2) 
                    {
                        if(maxn2 == club[i].b)
                        {
                            cnt2 ++ ;
                            ans += maxn2 ;
                        }
                        else if(maxn2 == club[i].a)
                        {
                            cnt1 ++ ;
                            ans += maxn2 ;
                        }
                    }
                    else if(cnt2 < n / 2 && cnt1 >= n / 2)
                    {
                        cnt2 ++ ;
                        ans += club[i].b;
                    }
                    else if(cnt1 < n / 2 && cnt2 >= n / 2)
                    {
                        cnt1 ++ ;
                        ans += club[i].a;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0 ;
}