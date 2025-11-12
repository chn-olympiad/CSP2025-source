#include <iostream>
#include <cstdio>
using namespace std;
int n, k, x, y;
long long a[500005];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] == 1) x++;
        if(a[i] == 0) y++;
    }
    if(x == n) cout << n - 1;
    else if(x + y == n)
    {
        if(k == 0) cout << y;
        else if(k == 1) cout << x;
    }
    return 0;
}
