#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int rp=0;
    if (a+b>c) rp++;
    if (a+c>b) rp++;
    if (b+c>a) rp++;
    cout << rp;
    return 0;
}
