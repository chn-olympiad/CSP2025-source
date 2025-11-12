#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,ans;
ll a[500010];
ll num = 0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(k <= 1){
        if(k == 0){
            for(int i = 1;i <= n;i++){
                if(a[i] == 0){
                    ans++;
                }
                else if(a[i] == 1 && a[i + 1] == 1){
                    ans++,i++;
                }
            }
            cout << ans;
            return 0;
        }
        else{
            for(int i = 1;i <= n;i++){
                if(a[i] == 1){
                    ans++;
                }
            }
            cout << ans;
            return 0;
        }
    }
    ll r = n;
    for(int i = n;i >= 1;i--){
        ll sum = 0;
        for(ll j = i;j <= r;j++){
            sum ^= a[j];
            if(sum == k){
                ans++;
                r = i - 1;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
