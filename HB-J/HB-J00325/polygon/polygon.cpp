#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
5
1 2 3 4 5
*/
const int maxn = 10010;
const int mod = 99824353;
int a[maxn]; // yuan shu zu
int qz[maxn]; // qian zhui he shu zu
int maxx[maxn]; // qu jian nei zui da shu zi
int ans = 0;
signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    scanf("%lld", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        qz[i] = qz[i - 1] + a[i];
        maxx[i] = max(maxx[i - 1], a[i]);
    }
    /*
    for(int i = 1; i <= n; ++i) {
        cout << maxx[i] << ' ';
    }
    cout << endl;
    for(int i = 1; i <= n; ++i) {
        cout << qz[i] << ' ';
    }
    */
    
    for(int ck = 3; ck <= n; ++ck) {
        for(int i = 1; i <= n - ck + 1; ++i) {
            if(qz[i + ck - 1] - qz[i - 1] > maxx[i + ck - 1] * 2){
                ans++;
            }
        }
    }
    printf("%lld", ans % mod);
    // i really wish i can get a good grade 233

    return 0;
}