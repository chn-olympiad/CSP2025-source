#include <iostream>
using namespace std;
typedef long long ll;
const int N = 19;
int n , m , a[N] , b[N] , log2[1 << N];
ll f[N][1 << N][N];
int count(int x){
    return x ? count(x >> 1) + (x & 1) : 0;
}
int main(){
    freopen("employ.in" , "r" , stdin);
    freopen("employ.out" , "w" , stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0;i < n;i++) log2[1 << i] = i;
    char ch;
    for (int i = 0;i < n;i++){
        cin >> ch;
        a[i] = ch ^ 48;
    }
    for (int i = 0;i < n;i++) cin >> b[i];
    for (int i = 0;i < n;i++){
        if (a[0] && b[i]) f[0][1 << i][1] = 1;
        else f[0][1 << i][0] = 1;
    }
    for (int j = 1;j < (1 << n);j++){
        int i = count(j) - 1;
        for (int k = 0;k <= i + 1;k++){
            for (int t = ~j & (1 << n) - 1;t;t ^= (t & -t)){
                int l = log2[t & -t];
                f[i + 1][j | (1 << l)][k + (a[i + 1] && b[l] > i + 1 - k)] += f[i][j][k];
            }
        }
    }
    ll ans = 0;
    for (int i = m;i <= n;i++) ans += f[n - 1][(1 << n) - 1][i];
    cout << ans % 998244353 << '\n';
    return 0;
}