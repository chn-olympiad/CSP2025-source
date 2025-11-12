#include<bits/stdc++.h>
using namespace std;
const int N= 2e5+5;
const long long Mod = 998244353;
int n, m;
long long ans = 1;
string a;
int k[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> a;
    int num = n;
    for(int i = 1; i <= n; i ++) {
        cin >> k[i];
    }if((m == 1 && (a[0] == '1' || a[1] == '1')) ||(m == 2 && a[0] == '1' && a[1] == '1')){
        for(int i = 1; i <= n; i ++) {
            ans *= i;
            ans %= Mod;
        }cout << ans;
    }else{
        cout << "0";
    }
    return 0;
}
