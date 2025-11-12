#include <bits/stdc++.h>

using namespace std;
const int N = 15 , M = 1e6 + 5;
int n , num[N] , x;
string s;
bool flag = 1;
int main()
{
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for(int i = 0 ; i < s.size() ; ++ i)
    {
        if('0' <= s[i] && s[i] <= '9')
        {
            x = s[i] - '0';
            num[x] ++;
        }
    }
    for(int i = 9 ; i >= 1 ; -- i)
    {
        for(int j = 1 ; j <= num[i] ; ++ j)
        {
            printf("%d" , i);
            flag = 0;
        }
    }
    if(flag)
    {
        printf("%d" , 0);
    }
    else
    {
        for(int j = 1 ; j <= num[0] ; ++ j)
        {
            printf("%d" , 0);
        }
    }
    return 0;
}
