#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, r = 1, c = 1, sc = 0;
    cin >> n >> m;
    vector<int>a(n * m, 0);
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i - 1];
        if(i == 1) sc = a[i - 1];
    }
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 1; i <= n * m; i++)
    {
        if(a[i - 1] == sc) break;
        if(((i - 1) / n) % 2 == 0) r++;
        else r--;
        if(r > n) r = n, c++;
        else if(r < 1) r = 1, c++;
    }
    cout << c << " " << r << endl;
    return 0;
}
/*
g++ -Wall -O2 -std=c++14 -static seat.cpp -o seat
*/
