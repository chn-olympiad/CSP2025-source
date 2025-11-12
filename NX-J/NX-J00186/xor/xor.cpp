#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor4.in","r",stdin);
    freopen("xor4.out","w",stdout);
    int n,r;
    cin>>n>>r;
    vector <int> a(n+1,0);
    vector <int> b(n+1,0);
    vector <int> c(n+1,0);
    int ones = 0,zeros = 0;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        if(a[i] == 1) ones++;
        else zeros++;
        b[i] = b[i-1]^a[i];
    }
    if(r <= 1){
        if(r == 1){
            cout<<ones<<endl;
        }
        else{
            int ans = zeros;
            for(int i = 1;i < n;i += 2){
                if(a[i] == 1&&a[i+1] == 1){
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
        return 0;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < i;j++){

            for(int k = j + i;k <= n;k += i){

                if((b[k] ^ b[k-i]) == r){
                    bool flag = 1;
                    for(int l = k-i+1;l <= k;l++){
                        if(c[l]) flag = 0;
                    }
                    if(!flag) continue;
                    for(int l = k-i+1;l <= k;l++){
                        c[l] = 1;
                    }

                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
