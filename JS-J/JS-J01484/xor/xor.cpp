#include <bits/stdc++.h>
using namespace std;
int a[500005],s[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,k1,ans = 0;
    cin >> n >> k1;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++){
        if (a[i] == k1){
            ans++;
            continue;
        }
        memset(s,0,sizeof(s));
        s[1] = a[i];
        for (int j = i + 1;j <= n;j++){
            bool flag = false;
            for (int k = 1;k <= j - i + 1;k++){
                if (s[k] == 0) s[k] = a[j];
                else s[k] ^= a[j];
                if (s[k] == k1){
                    ans++;
                    i = j;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
    }
    cout << ans;
    return 0;
}
