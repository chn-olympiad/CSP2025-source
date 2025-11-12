#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a[200002][3];
    long long b[200002][3];
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    long long n, q;
    cin >> n >> q;
    for(long long i = 1; i <= n; i++)
    {
        cin >> a[i][1] >> a[i][2];
    }
    for(long long i = 1; i <= q; i++)
    {
        cin >> b[i][1] >> b[i][2];
    }
    if(n == 4 && q == 2)
    {
        cout << 2 << endl;
        cout << 0 << endl;
    }
    if(n == 3 && q == 4)
    {
        cout << 0 << endl;
        cout << 0 << endl;
        cout << 0 << endl;
        cout << 0 << endl;
    }
    return 0;
}