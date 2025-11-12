#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5 , M = 15;
int n , m , a[N];
int ans[M][M];
int x , y , d;
int main()
{
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    scanf("%d %d" , & n , & m);
    for(int i = 1 ; i <= n * m ; ++ i)
    {
        scanf("%d" , & a[i]);
    }
    a[0] = a[1];
    sort(a + 1 , a + 1 + n * m);
    x = 0 , y = 1 , d = 1;
    for(int i = n * m ; i >= 1 ; -- i)
    {
        int X = x + d , Y = y;
        if(X > n)
        {
            X = x , d = -1 , Y = y + 1;
        }
        if(X < 1)
        {
            X = 1 , d = 1 , Y = y + 1;
        }
        x = X , y = Y;
        ans[x][y] = a[i];
    }
    for(int i = 1 ; i <= n ; ++ i)
    {
        for(int j = 1 ; j <= m ; ++ j)
        {
            if(ans[i][j] == a[0])
            {
                printf("%d %d" , j , i);
                return 0;
            }
        }
    }
    return 0;
}
