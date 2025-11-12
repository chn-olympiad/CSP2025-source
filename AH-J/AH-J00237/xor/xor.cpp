#include <bits/stdc++.h>
using namespace std;
int n, k, a[5005], ans[5005][5005], f[5005][5005], mem[5005];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            f[i][j]=f[i][j-1]^a[j];
            if(f[i][j]==k){
                mem[i]=min(mem[i], j-i);
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(mem[i]){
            for(int j=i; j>=1; j--) ans[j][n]++;
            i+=mem[i];
        }
        else{
            ans[i][n]=ans[i-1][n];
        }
    }
    cout << ans[1][n];
    return 0;
}
