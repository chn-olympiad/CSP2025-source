#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[500010];
int main(){
    freopen("w","xor.in",stdin);
    freopen("r","xor.out",stdout);
    cin >> n >> k;
    for (int i = 1;i <= n;i++) scanf("%d",&a[i]),a[i] ^= a[i - 1];
    for (int i = 1;i <= n;i++){
        for (int j = i;j <= n;j++){
            if ((a[i - 1] ^ a[j]) == k) ans++,i = j + 1;
        }
    }
    cout << ans;
    return 0;
}
