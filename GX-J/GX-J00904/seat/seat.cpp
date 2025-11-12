#include <bits/stdc++.h>
using namespace std;
int a[11][11];
int num[101];
int main()
{
    //freopen("seat2.in", "r", stdin);
    //freopen("seat.out", "w", stdout);
    int n, m, t;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) cin >> num[i];
    int k = num[1];
    for (int i = 1; i <= n * m; i++) 
    {
        for (int j = 1; j <= n * m; j++)
        {
            if (num[i] > num[j])
            {
                t = num[i];
                num[i] = num[j];
                num[j] = t;
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans++;
            if (num[ans] == k) 
            {
                cout << i << " " << j << endl;
                break;
            }
        }
    }
    return 0;


}