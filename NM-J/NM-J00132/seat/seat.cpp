#include <bits/stdc++.h>
using namespace std;
int n,m,cnt=1;
int c,r,sc;
int a[128];
int s[16][16];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n*m ; i++) cin >> a[i];
    sc = a[1];
    sort(a+1,a+1+n*m,greater<int>());

    for(int i = 1 ; i <= m ; i++)
    {
        if(i % 2 != 0)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                s[j][i] = a[cnt];
                cnt++;
            }
        }
        else
        {
            for(int j = n ; j >= 1 ; j--)
            {
                s[j][i] = a[cnt];
                cnt++;
            }
        }

    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s[i][j] == sc) cout << j << ' ' << i;
        }
    }

    return 0;
}
