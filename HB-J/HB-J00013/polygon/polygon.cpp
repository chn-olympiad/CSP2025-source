#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5009] = {},ans = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        ans += a[i];
    }
    sort(a + 1,a + n + 1);
    int ma = a[n];
    if(n < 3){
        cout << 0;
    } else if(n == 3){
        if(ans > ma * 2){
            cout << 1;
        } else {
            cout << 0;
        }
    }
    return 0;
}
