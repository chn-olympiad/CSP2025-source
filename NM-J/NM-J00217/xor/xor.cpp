#include <bits/stdc++.h>
using namespace std;
int n, k, l, a[500005], f[500005];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        f[i] = f[i - 1];
        if (a[i] == k){
            f[i]++;
            l = i + 1;
            continue;
        }
        else{
            int tmp = 0;
            for (int j = i; j >= l; j--){
                tmp ^= a[j];
                if (tmp == k){
                    f[i]++;
                    l = i + 1;
                    break;
                }
            }
        }
    }
    cout << f[n];
    return 0;
}
