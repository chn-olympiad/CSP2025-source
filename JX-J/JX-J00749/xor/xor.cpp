#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n,k;
    cin >> n >> k;
    if(k <= 1){
        for(int i = 1; i <= n; i ++) cin >> a[i];
        if(k == 0){
                int res = 0;
        for(int i = 1; i <= n; i ++){
            if(a[i] == 0) res ++;
        else if(a[i + 1] == 1) res ++,i ++;
        }}else{
                   int res = 0;
        for(int i = 1; i <= n; i ++){
            if(a[i] == 1) res ++;
        }
        cout << res << endl;
        }
    }else{
        int res = 0;
        for(int i = 1; i <= n; i ++){
            if(a[i] == k) res ++;
        }
        cout << res << endl;
        }
    }
    return 0;
}
