#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
char a[N], b[N];
int l = 0;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> a;
    for (int i = 0; a[i] != '\0'; i++)
        if (a[i]>='0' && a[i] <= '9')
            b[l++] = a[i];
    sort(b, b + l, greater<char>());
    if (b[0] == '0')
        cout << 0;
    else cout << b;
    cout << '\n';

    return 0;
}