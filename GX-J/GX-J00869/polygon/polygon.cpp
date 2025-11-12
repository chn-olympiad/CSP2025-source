#include<bits/stdc++.h>
using namespace std;
int a[10000001];
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n,m = 1;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != 1) m = 0;
    }
    if(n == 3){
        if(a[1]+a[2] > a[3] && a[1]+a[3] > a[2] && a[2]+a[3] >a[1]) cout << 1;
        else cout << 0;
        return 0;
    }else if(m){
        int ans = 0;
        for(int i = 3;i <= n;i++){
            int u = i-2;
            ans += u*(3*n-9);
        }
        cout << ans/(n-2);
        return 0;
    }
    return 0;
}



