#include <bits/stdc++.h>
using namespace std;

int n, k, c, d, maxc;
int arr[500005];
int val[500005];
int sel[500005];

int main () {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;
    c = 0, d = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] == 1) 
            c++;
        if (arr[i] == 0) 
            d++;
        val[i] = val[i - 1] ^ arr[i];
    }
    if (c + d == n && k == 0) {
        cout << n << endl;
        return 0;
    }
    // if (c + d == n && k == 1) {
    //     cout << d << endl;
    //     return 0;
    // }
    
    c = 0;
    for (int i = 1; i <= n; i++) {
        //c = 0;
        for (int j = i; j <= n; j++) {
            if (sel[j])
                continue;
            sel[j] = true;
            cout << "\t" << val[i] << " " << val[j] << endl;
            if ((val[j] ^ val[i]) == k)
                c++;
        }
        maxc = max(c, maxc);
        sel[i] = false;
    }
    cout << maxc << endl;
    return 0;
}
