#include<bits/stdc++.h>
using namespace std;
int n, m;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    long long mul = 1;
    for(int i = n; i >= n-m+1; i--){
        mul *= i;
        mul %= 998244353;
    }
    cout << mul;
    return 0;
}
