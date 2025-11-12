#include <bits/stdc++.h>
using namespace std;

const int N = 5000 + 10;
long long a[N], sum[N], BestMax[N][N];
int n;

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
//        cout << sum[i] << " ";
    }
    for(int i = 1; i <= n; i ++){
        for(int j = i; j <= n; j ++){
            BestMax[i][j] = max(BestMax[i][j - 1], a[j]);
//            cout << i << " " << j << " " << BestMax[i][j] << endl;
        }
    }
    long long ans = 0;
    for(int i = 1; i <= n; i ++){
        for(int len = 3; len <= n; len ++){
            int j = i + len;
            if(j > n)break;
            if(sum[j] - sum[i - 1] > 2 * BestMax[i][j]){
                ans ++;
                ans %= 998244353;
            }
        }
    }
    ans %= 998244353;
    cout << ans * 3 % 998244353;
    return 0;
}
