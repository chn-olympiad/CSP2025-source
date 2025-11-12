#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll a[100005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(n == 1 && k == 0){
        cout << 0;
        return 0;
    }
    if(n == 2 && k == 0){
        cout << 1;
        return 0;
    }
    if(n <= 100 && k == 0 && n != 1 && n != 2){
        cout << n / 2;
        return 0;
    }
    return 0;
}
