#include <bits/stdc++.h>
using namespace std;
int n , m , sc[110] , s , idx , cnt;
bool f = 1;
int main()
{
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    cin >> n >> m;
    for(int i=1 ; i<=n*m ; i++) cin >> sc[i];
    s = sc[1];
    sort(sc + 1 , sc + n * m + 1);
    for(int i=n*m ; i>=1 ; i--) if(sc[i] == s) idx = n * m - i + 1;
    for(int i=1 ; i<=m ; i++)
    {
        if(f)
        {
            for(int j=1 ; j<=n ; j++)
            {
                cnt ++;
                if(cnt == idx)
                {
                    cout << i << " " << j;
                    return 0;
                }
            }
            f = 0;
        }
        else
        {
            for(int j=n ; j>=1 ; j--)
            {
                cnt ++;
                if(cnt == idx)
                {
                    cout << i << " " << j;
                    return 0;
                }
            }
            f = 1;
        }
    }
}
