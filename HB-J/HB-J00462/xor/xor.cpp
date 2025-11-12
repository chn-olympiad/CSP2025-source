#include<bits/stdc++.h>
using namespace std;
int a[500001], match[500001], pos[1048576], nxt[500002];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, p = 1, cnt = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    nxt[n + 1] = 0x7f7f7f7f;
    for(int i = n; i >= 1; i--){
        pos[a[i]] = i;
        match[i] = pos[a[i - 1] ^ k];
        if(match[i])nxt[i] = min(nxt[i + 1], match[i]);
        else nxt[i] = nxt[i + 1];
    }
    while(p <= n){
        if(nxt[p] <= n)cnt++;
        p = nxt[p] + 1;
    }
    cout << cnt;
    return 0;
}
