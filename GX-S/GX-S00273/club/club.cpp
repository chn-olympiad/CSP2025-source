#include<bits/stdc++.h>
using namespace std;
int t, n, ans;
int a, b, c;
int sum[100001];
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n;
        ans = 0;
        for(int i = 1; i <= n; i++){
            cin >> a >> b >> c;
            if(a >= b && a >= c)
                ans += a;
            else if(b >= a && b >= c)
                ans += b;
            else if(c >= b && c >= a)
                ans += c;
        }
        cout << ans << endl;
    }
    return 0;
}
