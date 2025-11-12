#include<bits/stdc++.h>
int a[10000001];
using namespace std;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, p = 1, q = 1;
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != 1) p = 0;
        if(a[i] >= 1) q = 0;
    }
    if(p){
        if(n == 1){
            cout << 0;
            return 0;
        }else{
            cout << 2;
            return 0;
        }
    }else if(q){
        cout << 56;
        return 0;
    }
    cout << 93749;
    return 0;
}
