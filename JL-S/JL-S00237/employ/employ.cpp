#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n;
    cin >> n;
    long long m = 1;
    for(int i= 1; i <= n;i++){
        m = (m * i )% 998244353;
    }
    cout << m;
    return 0;
}
