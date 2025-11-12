#include <bits/stdc++.h>

using namespace std;
const int N = 5e3 + 5 , mod = 998244353;
int n , a[N];
int ans;
int g;
int an[N];
void dfs(int i , int Max , int sum , int cnt)
{
    if(sum > Max * 2 && cnt == g)
    {
        ans ++;
        ans %= mod;
        return;
    }
    if(i == n + 1)
    {
        return;
    }
    an[cnt + 1] = a[i];
    dfs(i + 1 , max(Max , a[i]) , sum + a[i] , cnt + 1);
    an[cnt + 1] = 0;
    dfs(i + 1 , Max , sum , cnt);
}
int main()
{
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    scanf("%d" , & n);
    for(int i = 1 ; i <= n ; ++ i)
    {
        scanf("%d" , & a[i]);
    }
    sort(a + 1 , a + 1 + n);
    for(int i = 3 ; i <= n ; ++ i)
    {
        g = i;
        dfs(1 , 0 , 0 , 0);
    }
    printf("%d" , ans);
    return 0;
}
