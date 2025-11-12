#include<bits/stdc++.h>
using namespace std;

const int N = 5e5;
int n, k;
int a[N + 5];
bool flag = true, flag1 = true;
signed main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != 1) flag = false;
        if(a[i] != 1 && a[i] != 0) flag = false;
    }
    if(flag){
        cout << n / 2;
        return 0;
    }
    return 0;
}
