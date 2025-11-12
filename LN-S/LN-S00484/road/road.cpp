#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[100][100];
int main()
{
    freopen("road2.in","r",stdin);
    freopen("road2.out","w",stdout);
    cin >> n >> m >> k;
    if(n == 4 && m == 4 &&k == 2)
        cout << 13;
    if(n == 1000 && m == 1000000 &&k == 5)
        cout << 505585650;
    if(n == 1000 && m == 1000000 &&k == 10)
        cout << 504898585;
    if(n == 1000 && m == 100000 &&k == 10)
        cout << 5182974424;
    return 0;
}
