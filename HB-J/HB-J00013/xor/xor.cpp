#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[1000009] = {};
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(n == 1){
        if(a[1] == k){
            cout << 1;
        }
    }
    return 0;
}
