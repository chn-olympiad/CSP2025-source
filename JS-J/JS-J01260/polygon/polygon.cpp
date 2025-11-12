#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, a[5005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(long long i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if(n == 3){
        if(a[1] + a[2] > a[3]) cout << 1;
        else cout << 0;
    }
    else if(n < 3) cout << 0;
    else{
        bool flag = false;
        for(long long i = 1;i <= n;i++){
            if(a[i] > 1){
                flag = true;
                break;
            }
        }
        if(!flag) cout << 0;
        else cout << n;
    }
    return 0;
}
