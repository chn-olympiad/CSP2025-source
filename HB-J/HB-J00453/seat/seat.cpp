#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    int n , m;
    cin >> n >> m;
    int len = n * m;
    int a[len+5];
    for(int i = 1 ; i <= len ; i++)
    {
        cin >> a[i];
    }
    int ans = a[1];
    sort(a , a+len+1);
    int t;
    for(int i = len , j = 1; i >= 1; i-- , j++)
    {
        if(a[i] == ans) t = j;
    }
    int c , r;
    if(t % n != 0) c = t / n + 1;
    else c = t / n;
    if(c % 2) r = t % n;
    else r = n - (t % n) + 1;
    cout << c << " " << r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
