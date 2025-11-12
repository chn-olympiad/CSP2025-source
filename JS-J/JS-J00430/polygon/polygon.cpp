#include<bits/stdc++.h>
using namespace std;
long long n, k, a[4], tmp, cnt;
int main(){
    freopen("polygon.in", "r",stdin);
    freopen("polygon.out", "w",stdout);
    cin >> n;
    if(n == 3){
        cin >> a[1] >> a[2] >> a[3];
        tmp = a[1] + a[2] + a[3];
        if(max(a[1], max(a[2], a[3]))* 2 > tmp)cout << 1;
        else cout << 0;
    }
    else {
        for(int i = 3;i <= n;i++){
            for(int j = 0;j < i;j++){
                tmp *= (n - j);
                tmp %= 988244353;
                k *= (j + 1);
                k %= 988244353;
            }
            cnt += (tmp / k);
            cnt %= 988244353;
        }
        cout << (int)cnt;
    }
    return 0;
}
