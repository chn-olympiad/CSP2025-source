#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[5001];
int main()
{
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    int n = 0;
    cin >> n;
    if(n < 3){
        cout << 0;
        return 0;
    }
    int ans = 0;
    for(int i = 0;i < n;++i){
        cin >> a[i];
    }
    sort(a , a + n);
    for(int i = 0;i < n;++i){
        for(int j = i + 1;j < n;++j){
            for(int k = j + 1;k < n;++k){
                if(a[i] + a[j] + a[k] > a[k] * 2) ans ++;
            }
        }
    }
    cout << ans % mod;
    return 0;
}

