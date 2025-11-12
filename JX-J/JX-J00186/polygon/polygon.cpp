#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    if(n == 3){
        if(max(a[1], max(a[2], a[3]))*2 < a[1] + a[2] +a[3]) cout << 1;
        else cout << 0;
    }
    else{
        long long sum = 0;
        for(int i = 3; i <= n; i++){
            long long s1 = 1, s2 = 1;
            for(int j = n; j >= n-i+1; j--){
                s1 = s1 * j;
            }
            for(int j = i; j >= 2; j--){
                s2 = s2 * j;
            }
            sum = (sum+ s1 / s2 % 998244353) % 998244353;
        }
        cout << sum;
    }
    return 0;
}
