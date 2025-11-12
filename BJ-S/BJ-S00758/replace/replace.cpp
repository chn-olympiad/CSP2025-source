#include <bits/stdc++.h>
using namespace std ;
#define int long long
string s[200010][3] , s1[200010][3];
int p[200010] , p2[200010] , P[200010] , P1[200010];
int n , q ;
void solve2()
{
    for(int i = 1 ; i <= n ; i ++)
        p[i] = s[i][1].find("b") , P[i] = s[i][2].find("b"); 
    for(int i = 1 ; i <= q ; i ++)
        p2[i] = s1[i][1].find("b") , P1[i] = s1[i][2].find("b");
    for(int i = 1 ; i <= q ; i ++)
    {
        int ans = 0 ;
        for(int j = 1 ; j <= n ; j ++)
        {
            if(p[j] >= p2[i] && P[j] <= P1[i] && (p[j] - P[j]) == (p2[i] - P1[i]))
                ans ++;
        }
        cout << ans << endl;
    }
}
bool check1(int x , int cur , int q_cur)
{
    for(int i = 0 ; i < x ; i ++)
    {
        if(s1[q_cur][1][i] != s1[q_cur][2][i])
            return 0 ;
    }
    for(int i = x ; i <= x + s[cur][2].size() - 1 ; i ++)
    {
        if(s[cur][2][i - x] != s1[q_cur][2][i])
            return 0 ;
    }
    for(int i = x + s[cur][2].size() ; i <= s1[q_cur][2].size() - 1 ; i ++)
    {
        if(s1[q_cur][1][i] != s1[q_cur][2][i])
            return 0 ;
    }
    return 1 ;
}
void solve1()
{
    int ans = 0 ;
    for(int i = 1 ; i <= q ; i ++)
    {
        ans = 0 ;
        for(int j = 1 ; j <= n ; j ++)
        {
            int pos = s1[i][1].find(s[j][1]) ;   
            if(check1(pos , j , i) && pos <= s1[i][1].size())
            { 
                ans ++ ;
            }
        }
        cout << ans << endl;
    }
}
signed main()
{
    freopen("replace.in" , "r" , stdin) ;
    freopen("replace.out" , "w" , stdout) ;
    cin >> n >> q ;
    for(int i = 1 ; i <= n ; i ++)
        cin >> s[i][1] >> s[i][2] ;
    for(int i = 1 ; i <= q ; i ++)
        cin >> s1[i][1] >> s1[i][2] ;
    if(n <= 10000 || q == 1)
        solve1() ;
    else    
        solve2() ;
    return 0 ;
}