#include <iostream>
#include <cstdio>
using namespace std;
int n, a[5005], num;
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        num += a[i];
    }
    if(n % 2 == 1) cout << num - 1 - n;
    else cout << n / 2;
    return 0;
}
