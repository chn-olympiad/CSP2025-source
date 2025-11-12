#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int c[6000] , cnt = 0 , a[6000] , n;
void dfs(int d , int s , int p)
{
    if(d == s+1)
    {
        int sum = 0 , mx = 0;
        for(int i = 1 ; i <= s ; i++)
        {
            sum += c[i];
            mx = max(mx , c[i]);
        }
        if(sum > mx*2){
            cnt++;
        }
        return;
    }
    for(int i = p+1 ; i <= n ; i++)
    {
        c[d] = a[i];
        dfs(d+1 , s , i);
    }
}
int main()
{
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    cin >> n;
    for(int i = 1; i <= n ; i++)
    {
        cin >> a[i];
    }
    for(int i = 3 ; i <= n ; i++)
    {
        dfs(1 , 3 , 0);
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

