#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll n, k, a[500005], ans, sum, r;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == k){
            ans++;
            continue;
        }
        sum = a[i];
        r = 0;
        for(int j = i + 1; j <= n; j++){
            sum ^= a[j];
            if(sum == k){
                r = j;
                break;
            }
        }
        ans++;
        i = r + 1;
    }
    cout << ans;
    return 0;
}
