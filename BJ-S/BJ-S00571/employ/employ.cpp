#include<bits/stdc++.h>
using namespace std;
int n , m , c[505] , p[505] , ans;
string s;
inline int solve()
{
    int cnt = 0 , cnq = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(s[i - 1] == '0')
        {
            cnq++;
        }
        else
        {
            if(c[p[i]] <= cnq)
            {
                cnq++;
            }
            else
            {
                cnt++;
            }
        }
    }
    if(cnt >= m)
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("employ.in" , "r" , stdin);
    freopen("employ.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> c[i];
    }
    if(n > 11)
    {
        cout << '0';
        return 0;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        p[i] = i;
    }
    ans += solve();
    while(next_permutation(p + 1 , p + n + 1))
    {
        ans += solve();
    }
    cout << ans;
    return 0;
}
/*
T4 employ (10pts)

思考 4

代码 5

对拍 1
*/