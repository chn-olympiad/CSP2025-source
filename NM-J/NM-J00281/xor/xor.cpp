#include<bits/stdc++.h>
using namespace std;
int n, k, ans;
int a[1000010];
bool pan = true;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != 1){
            pan = false;
        }
    }
    if(k == 0 and pan == true){
        cout << n/2;
    }else if(k == 0){
        for(int i = 1;i <= n;i++){
            if(a[i] == 0){
                ans++;
            }else if(a[i+1] == 1 and a[i] == 1){
                ans++;
                i++;
            }
        }
        cout << ans;
        return 0;
    }else if(k == 1){
        for(int i = 1;i <= n;i++)
        if(a[i] == 1){
            ans++;
        }
        cout << ans;
    }
    return 0;
}
