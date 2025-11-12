#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,k,a[N];
bool f;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] == 0){
            f = true;
        }
    }
    if(k == 0 && !f){
        cout << 0;
        return 0;
    }
    if(k == 0 && f){
        int ans = 0;
        for(int i = 1;i <= n;i++){
            if(a[i] == 0){
                ans++;
            }
            else if(a[i] == a[i + 1]){
                ans++;
                i++;
            }
        }
        cout << ans;
        return 0;
    }
    for(int x = 1;x <= 300;x++){
        if(k == x){
            int ans = 0;
            for(int i = 1;i <= n;i++){
                if(a[i] == x){
                    ans++;
                }
                else if((a[i] ^ a[i + 1]) == x){
                    ans++;
                    i++;
                }
            }
            cout << ans;
            return 0;
        }
    }
    return 0;
}
