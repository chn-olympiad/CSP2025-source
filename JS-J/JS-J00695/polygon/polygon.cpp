#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 200007;
int n, stk[N];
bool check(int m){
    int sum = 0, maxn = -99999;
    for(int i = 1; i <= m; i++){
        sum += stk[i];
        maxn = max(maxn, stk[i]);
    }
    if(sum > maxn * 2) return true;
    return false;
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> stk[i];
    if(n < 3) cout << 0;
    else if(n == 3 && check(3) == true) cout << 1;
    else if(n == 3 && check(3) == false) cout << 0;
    return 0;
}
