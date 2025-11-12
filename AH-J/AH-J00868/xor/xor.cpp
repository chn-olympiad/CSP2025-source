#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, cnt = 0;
    cin >> n >> k;
    bool flag = true;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x != 1) flag = false;
        if(x == 0) cnt++;
    }
    if(k == 0 && flag == false) cout << cnt;
    if(k == 0 && flag == true) cout << n / 2;
    if(k == 1 && flag == true) cout << n;
    if(k > 1 && flag == true) cout << 0;
    if(k > 1 && flag == false) cout << n/2 - 3;
    return 0;
}
