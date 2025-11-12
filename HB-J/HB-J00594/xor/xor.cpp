#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 10;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k,nc[MAX],ans = 0,f = 1,f0 = 0,ff1 = 0;
    bool fl[MAX] = {0};
    cin >> n >> k >> nc[0];
    if(nc[0] != 1) f = 0;
    if(nc[0] == 0) f0++;
    for(int i = 1;i < n;i++){
        cin >> nc[i];
        if(nc[i] != 1) f = 0;
        if(nc[i] == 0) f0++;
        if(nc[i] == 1 && nc[i - 1] == 1 && fl[i - 1] == 0){
            ff1++;
            fl[i] = 1;
        }
    }
    for(int i = 0;i < n;i++){
        if(nc[i] == k){
            ans++;
        }

    }
    if(k == 0 && f){
        cout << n / 2;
        return 0;
    }else if(0 <= k && k <= 1){
        if(k == 0){
            cout << f0 + ff1;
        }
        return 0;
    }
    cout << ans;
    return 0;
}
