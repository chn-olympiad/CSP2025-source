#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
ll n,k,cnt;
ll num[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(ll i = 1;i <= n;i++){
        cin >> num[i];
    }
    for(ll i = 1;i <= n;i++){
        ll ans = num[i] ^ num[i];
        for(ll j = i + 1;j < n;j++){
            cout << ans << " kjsdhf ";
            if(ans == k){
                cnt ++;
                i = j + 1;
            }
            else{
                ans ^= num[j];
            }
        }
    }
    cout << cnt <<endl;
    return 0;
}
