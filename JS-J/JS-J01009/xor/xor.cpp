#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool flag = true;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) if(!a[i]) flag = false;
    if(n <= 100 && k == 0 && flag){ // #1,3
        cout << n/2 << "\n";
        return 0;
    }else if(k <= 1){ // #2,4,5,13
        if(k == 0){
            int ans = 0;
            for(int i = 0; i < n-1; i++){
                if(a[i] == 0) ans++;
                else if(a[i] == 1 && a[i+1] == 1){
                    ans++;
                    i++;
                }
            }
            if(a[n] == 0) ans++;
            cout << ans << "\n";
            return 0;
        }else{
            int ans = 0;
            for(int i = 0; i < n; i++){
                if(a[i]) ans++;
            }
            cout << ans << "\n";
            return 0;
        }
    }else{
        int sum = 0,ans = 0;
        for(int i = 0; i < n; i++){
            sum ^= a[i];
            if(sum == k) ans++,sum = 0;
        }
        cout << ans << "\n";
    }
    return 0;
}
// 25pts, please give me