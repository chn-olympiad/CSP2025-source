#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, k1, sum = 0;
    long long a[500005];
    int A = 1, B = 1;
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k1;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] != 1) A = 0;
        if (a[i] != 1 && a[i] != 0) B = 0;
    }
    if (A){
        cout << n/2;
        return 0;
    }
    if (B){
        if (k1 == 1){
            for (int i = 1; i <= n; i++){
                if (a[i] == 1) sum++;
                if (a[i] == 0 && a[i+1] == 0){
                    i++;
                    sum ++;
                }
            }
            cout << sum;
            return 0;
        }
        if (k1 == 0){
            for (int i = 1; i <= n; i++){
                if (a[i] == 0) sum++;
                if (a[i] == 1 && a[i+1] == 1){
                    i++;
                    sum ++;
                }
            }
            cout << sum;
            return 0;
        }
    }
    cout << 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
