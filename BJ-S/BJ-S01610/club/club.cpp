#include<bits/stdc++.h>
using namespace std;
int t, n, sum[1000005], a, b, c;
int main()
{
     freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
     cin >> t;
     for(int j = 1; j <= t; j++)
     {
         cin >> n;
         for(int i = 1; i <= n; i++)
         {
             cin >> a>> b >> c;
             sum[j] += max(a, max(b, c));
         }
     }
    for(int j = 1; j <= t; j++)
     {
         cout << sum[j]<<'\n';
     }
    return 0;
}
