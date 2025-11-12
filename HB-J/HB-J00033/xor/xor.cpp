#include <bits/stdc++.h>
using namespace std;

int n, k, a[500005], quan[500005];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if (k == 0){
        int sum = 0;
        for (int i = 1; i <= n; i++){
            if (a[i] == 0)
                sum++;
        }
        cout << sum;
        return 0;
    }
    else{
        int sum = 0;
        int sr = 1;
        quan[0] = a[1];
        quan[1] = a[1];
        for (int i = 2; i <= n; i++){
            quan[i] = quan[i - 1] ^ a[i];
        }
        for (int l = 1; l <= n; l++){
            for (int r = l; r <= n; r++){
                if (l <= sr)
                    continue;
                int q = quan[r] ^ quan[l - 1];
                if(q == k){
                    sum++;
                    sr = r;
                    //cout << l << " " << r << "\n";
                }

            }
        }
        cout << sum + 1;
        return 0;
    }
    return 0;
}
