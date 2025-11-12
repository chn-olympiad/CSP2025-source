#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n, m;
    cin >> a[i];
    int a[n + 10];
    int cnt = 0, cnt0 = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] == 1){
            cnt++;
        }
        if(a[i] == 0){
            cnt0++;
        }
    }
    if(cnt == n){
        if(m == 0){
            cout << n / 2;
        }else{
            cout << n;
        }
    }
    if(cnt0 + cnt == n){
        if(m == 0){
            cout << m + cnt / 2;
        }
        else{
            cout << cnt;
        }
    }
    return 0;
}
