#include <bits/stdc++.h>
using namespace std;
long long a[500001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,cnt = 0;
    cin >> n >> k;
    for (int i = 1;i <= n;i++) cin >> a[i];
    if (k == 0){
        for (int i = 1;i <= n;i++) if (a[i] == 0) cnt++;
        cout << cnt;
        return 0;
    }
    for (int l = 1;l <= n;l++){
        long long xorus = a[l];
        if (xorus == 0) continue;
        if (xorus == k){
            cnt++;
        }
        for (int r = l+1;r <= n;r++){
            if (a[r] == 0) continue;
            xorus ^= a[r];
            if (xorus == k){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
