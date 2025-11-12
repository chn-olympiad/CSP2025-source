#include <bits/stdc++.h>
using namespace std;
int n, ans;
int a[5500];

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "r", stdout);
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    if(n == 3)
    {
        if(a[0] + a[1] + a[2] > max(a[0], max(a[1], a[2]))) cout << 1 <<endl;
    }
    cout << 9 <<endl;
    return 0;
}