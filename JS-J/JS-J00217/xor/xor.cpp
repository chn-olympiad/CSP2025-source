#include <bits/stdc++.h>
using namespace std;
int a[500010];
int n, k, cnt, y = 0;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        int x;
        for (int j = i; j > y; j--){
            if(j == i){
                x = a[i];
            } else {
                x = (x ^ a[j]);
            }
            if(x == k){
                cnt++;
                y = i;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}
