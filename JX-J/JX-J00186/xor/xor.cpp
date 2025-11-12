#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, cnt = 0, s1 = 0, s0 = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(a[i] == 1) s1++;
        else if(a[i] == 0) s0++;
    }
    int x = a[1];
    for(int i = 2; i <= n; i++){
        if(x == k){
            x = a[i];
            cnt++;
        }
        else{
            x ^= a[i];
        }
    }
    if(x == k) cnt++;
    if(k == 1) cout << s1;
    else if(k == 0) cout << s0;
    else cout << cnt;
    return 0;
}
