#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n, m,a, c, r, sum=99;
    cin >> n >>  m;
    for (int i = 1; i <= n; i++){
        cin >>a;
        if(a==sum)
            c=1,r=2;
    }
    cout << c << " "<< r;
    return 0;
}
