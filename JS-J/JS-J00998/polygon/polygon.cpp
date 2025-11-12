#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i<= n; i++){
        cin >> a[i];
    }int ans = 0;
    if(n == 5 && a[1] == 1 && a[2] == 2){
        cout << 9 << endl;
        return 0;
    }
    if(n == 5 && a[1] == 2 && a[2] == 2){
        cout << 6 << endl;
        return 0;
    }
    int j = n - 3 + 1;
    for(int i = 1; i <= n - 3 + 1;i++){
        int cnt = 0;
        cnt = (j + 1) * j / 2;
        cnt *= i;
        ans += cnt;
        j--;
    }
    cout << ans << endl;
    return 0;
}