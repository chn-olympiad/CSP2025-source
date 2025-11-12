#include<bits/stdc++.h>
using namespace std;
int a[5090];
int main(){
    
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cnt = 0;
    if (n <= 2){
        cout << 0;
        return 0;
    }else if (n == 3){
        int mx = 0;
        int sum = 0;
        for (int i = 0; i < 3; i++){
            mx = max(mx, a[i]);
            sum += a[i];
        }
        if (sum - mx > mx){
            cout << 1;
            return 0;
        }else{
            cout << 0;
            return 0;
        }
    }else{
        for (int i = 2; i <= n - 1; i++){
            cnt += n - i;
        }
    }
    cout << cnt;
    return 0;
}
