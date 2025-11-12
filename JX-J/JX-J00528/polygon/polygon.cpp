#include <iostream>
#include <algorithm>
using namespace std;
int n;
const int N = 5e3 + 5;
const int mod = 998244353;
int a[N];
long long cnt[N];
void mu(long long &x){
    if(x >= mod) x -= mod;
}
void add(int x){
    for(int i = 5001;i >= 0;i--){
        int nxt = min(5001, i + x);
        cnt[nxt] += cnt[i];
        mu(cnt[nxt]);
    }
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    cnt[0] = 1;
    long long ans = 0;
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;i++){
        for(int j = a[i] + 1;j <= 5001;j++){
            ans += cnt[j];
            mu(ans);
        }
        add(a[i]);
    }
    cout << ans;
    return 0;
}
