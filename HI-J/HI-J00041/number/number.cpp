#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r", stdin);
    freopen("seat.out","W", stdout);
    int n, m;
    cin >> n >> m;
    int s[n*m+1] = {};
    for(int i = 1; i <= n*m; i++)
    {
        cin >> s[i];
    }
    int c = s[1];
    sort(s + 1, s + m*n + 1);
    int cnt = 0;
    for(int i = 1; i <= m; i++)
    {
        if(i%2 == 0)
        {
            for(int j = n; j>=1; j--)
            {
                cnt++;

                if(s[cnt] == c)
                {
                    cout << j << " " << i;
                    return 0;
                }
            }
        }
        else
        {
            for(int j = 1; j <= n; j++)
            {
                cnt++;

                if(s[cnt] == c)
                {
                    cout << j << " " << i;
                    return 0;
                }
            }
        }
    }
    return 0;
}
