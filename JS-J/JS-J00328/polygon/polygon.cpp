#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    if(n == 3){
        if(a[1] + a[2] > a[3] && a[2] + a[3] > a[1] && a[1] + a[3] > a[2]) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for(int l = 0;l < n - 2;l++){
        for(int r = l + 2;r < n;r++){
            int sum = 0, mx = 0;
            for(int i = l;i <= r;i++){
                sum += a[i];
                mx = max(mx, a[i]);
            }
            if(sum > 2 * mx) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
