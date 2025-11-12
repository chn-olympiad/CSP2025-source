#include <bits/stdc++.h>
using namespace std;

int a[5005];

int main()
{
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    int n , k;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    int maxa = max(max(a[1] , a[2]) , a[3]);
    if(a[1] + a[2] + a[3] >  maxa * 2) ans = 1;
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
