#include <bits/stdc++.h>
using namespace std;

// ^ is xor
int n, k, a[500005];

/*void xxor(int i, int ks, bool zkz, int xx){
    printf("xxor(i=%d, ks=%d, zkz=%d, xx=%d)\n", i, ks, zkz, xx);
    if (i == n){
        if (xx == k) ks++;
        if (ks > mx) mx = ks;
        return ;
    }
    if (zkz){
        xx = (xx ^ a[i]);
        if (xx == k){
            for (int j = i + 1; j <= n; j++){
                xxor(j, ks + 1, 0, 0);
            }
        }else{
            xxor(i + 1, ks, 1, xx);
        }
    }else{
        xxor(i + 1, ks, 0, 0);
        xx = a[i];
        if (xx == k){
            for (int j = i + 1; j <= n; j++){
                xxor(j, ks + 1, 0, 0);
            }
        }else{
            xxor(i + 1, ks, 1, xx);
        }
    }
    return ;
}*/

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ks = 0, kj = 0;
    for (int i = 1; i <= n; i++){
        int nn = 0;
        for (int j = i; j > kj; j--){
            nn = (nn ^ a[j]);
            if (nn == k){
                kj = i;
                ks++;
                break;
            }
        }
    }
    cout << ks;
    return 0;
}
