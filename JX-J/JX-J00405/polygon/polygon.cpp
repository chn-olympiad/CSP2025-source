#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 5e3 + 10;
int n,a[N];
bool f;
long long ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != 1){
            f = true;
        }
    }
    if(!f){
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                ans++;
            }
        }
        cout << ans << endl;
        return 0;
    }
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            long long cnt = 0,mx = -1;
            for(int k = i;k <= j;k++){
                cnt += (long long)a[k];
                mx = max(mx,(long long)a[k]);
            }
            if(cnt > 2 * mx){
                ans++;
            }
        }
    }
    cout << ans % mod;
    return 0;
}
