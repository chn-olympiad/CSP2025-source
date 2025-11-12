#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005], zz;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin>>s;
    for (auto i : s)
        if (i>='0' && i<='9')
            a[++zz]=i-'0';
    sort(a+1, a+1+zz);
    for (int i=zz; i>=1; i--) cout<<a[i];
    return 0;
}
