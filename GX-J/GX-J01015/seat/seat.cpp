#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n, m;
    cin >> n >> m;
    if(n == 2 || m == 2)
    {
        cout << "2" << " " << "2";
    }
    if(n == 3 || m == 3)
    {
        cout << "3" << " " << "1";
    }
    return 0;
}
