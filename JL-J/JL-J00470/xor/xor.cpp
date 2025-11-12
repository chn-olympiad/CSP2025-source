#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    bool one_flag = 0;
    long long n,k,r,cnt = 0,one = 0,zero = 0;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i] != 1){
            one_flag = 1;
        }
    } if(one_flag == 0){
        cout << n/2;
        return 0;
    } else {
        for(int i=1;i<=n;i++){
            if(a[i] == 1){
                one++;
            } else {
                zero++;
            }
        } if(k == 1){
            if(one > zero){
                cout << zero + (one-zero / 3);
            } else {
                cout << one;
            }
        } else {
            cout << (zero/2)+(one/2);
        }
    }
    return 0;
}
