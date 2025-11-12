#include<bits/stdc++.h>
using namespace std;
int a[5005];
int num[5005];
int main(){
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    int n;
    cin >> n;
    int flag = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != 1){
            flag = 0;
        }
    }

    sort(a+1 , a+n+1);
    if(n == 3){
        if(a[1] + a[2] > a[3]){
            cout << 1;
            return 0;
        }
        else{
            cout << 0;
            return 0;
        }
    }
    if(flag == 1){
        int z[5005] = {};
        z[0] = 1;
        for(int i = 1; i <= n; i++){
            z[i] = z[i-1] * (n-i+1) / i % 998244353;
        }
        int aa[5005] = {};
        for(int i = 3; i <= n; i++){
            aa[i] = (aa[i-1] + z[i]) % 998244353;
        }
        cout << aa[n];
    }
    return 0;
}
