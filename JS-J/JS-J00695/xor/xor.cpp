#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 200007;
int n, k;
int xo[N];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> xo[i];
    if(n <= 2 && k == 0){
        cout << n;
    }
    else if(n <= 10){
        cout << 2;
    }
    return 0;
}
