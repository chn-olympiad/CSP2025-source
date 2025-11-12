#include <bits/stdc++.h>
using namespace std;
long long n, m, as=1, c;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> s;
    for (int i=1;i<=n;i++){
        cin >> c;
        as *= i;
        as %= 998244353;
    }
    cout << as;
    return 0;
}
