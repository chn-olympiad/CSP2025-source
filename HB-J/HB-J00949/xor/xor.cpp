#include<bits/stdc++.h>
using namespace std;
int a[50001];
int s[20000][20000];
int main (){
    freopen ("xor.in","r",stdin);
    freopen ("xor.out","w",stdout);
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i){
        s[i][i] = a[i];
        for (int j = i+1; j <= n; ++j){
            s[i][j] = s[i][j-1] ^ a[j];
        }
    }

    int i = 1;
    for (int j = 1; j <= n; ++j){
        if (s[i][j] == k){
            ++ans;
            i = j+1;
        }
        if (j > n && i < n){
            ++i;
            j = i;
        }
    }
    cout << ans;
    return 0;
}
