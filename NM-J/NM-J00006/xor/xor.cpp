#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], cnt;
int main(){
    freopen("xor6.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k >> a[1];
    for (int i = 2;i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++){
        int f[500005];
        memset(f, 0, sizeof(f));
        f[i] = a[i];
        for (int j = i;j <= n;j++)
        {
            f[j] = (a[j] ^ f[j - 1]);
            if (f[j] == k){
                cnt++;
                //cout << i << " " << j << "\n";
                i = j;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}
