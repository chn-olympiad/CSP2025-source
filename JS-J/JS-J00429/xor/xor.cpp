#include <bits/stdc++.h>

using namespace std;

int n, k, a[500010], num, ans;

bool flag = 1;

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] == 1){
            num++;
        }
        if(a[i] == 0){
            ans++;
        }
    }
    if(k == 0){
        a[0] = (a[1] ^ 1);
        a[n + 1] = (a[n] ^ 1);
        for(int i = 1;i < n;i += 2){
            ans += (!(a[i] ^ a[i + 1]));
        }
        cout << ans << endl;
    }else{
        cout << num << endl;
    }

    return 0;
}