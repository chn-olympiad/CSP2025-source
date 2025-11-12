#include <bits/stdc++.h>
using namespace std;
int n , a[5050] , ans;
void dfs(int i , int idx , int cnt , int mx)
{
    cnt += a[i];
    mx = max(mx , a[i]);
    if(2 * mx < cnt) idx ++;
    if(i == n)
    {
        ans += idx;
        return ;
    }
    dfs(i + 1 , idx , cnt , mx);
    return ;
}
int main()
{
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    cin >> n;
    for(int i=1 ; i<=n ; i++) cin >> a[i];
    sort(a + 1 , a + n + 1);
    dfs(1 , 0 , 0 , 0);
    cout << ans;
    return 0;
}
