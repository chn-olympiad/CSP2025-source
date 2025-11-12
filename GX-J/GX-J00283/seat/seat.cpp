#include<bits/stdc++.h>
using namespace std;

long long n, m;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    long long c = n*m;
    char a[c];
    cin >> a;
    sqrt(a+1, a+c+1);
    return 0;
}
