#include <bits/stdc++.h>
using namespace std;
int n, k, ans = 0;
int a[50050];
int b[50050];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    memset(b, 0, sizeof(b));
    bool t1 = true, t2 = true;
    int s0 = 0, s1 = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 0)s0++;
        if(a[i] == 1)s1++;
        if(a[i] != 1)t1 = false;
        if(a[i] != 1 && a[i] != 0)t2 = false;
    }
    if(t1){
        ans = s1 / 2;
    }
    else if(t2){
        if(k == 1)ans = s1;
        else {
            for(int i = 1; i <= n - 1; i++){
                if(a[i] == 1 && a[i + 1] == 1 && b[i] == 0 && b[i + 1] == 0){
                    ans++;
                    b[i] = 1;
                    b[i + 1] = 1;
                }
            }
            ans += s0;
        }
    }
    else {
        int x = 0;
        for(int i = 1; i <= n; i++){
            if(x ^ a[i] == k){
                ans++;
                x = 0;
            }
            else x ^= a[i];
        }
    }
    cout << ans << endl;
    return 0;
}
