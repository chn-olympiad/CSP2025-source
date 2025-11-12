#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000;
long long n,k;
long long a[maxn];
int t[maxn];
long long dp[maxn][maxn];
int bg[maxn];
int xxor(int x,int y){
    if(x == 1 && y == 0){
        return 1;
    }else if(x == 0 && y == 1){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    for(int i = 1;i<=n;i++){
        int comp = a[i];
        for(int j = i;j<=n;j++){
            comp = xxor(comp,a[j]);
            if(comp == k){
                dp[i][j] = 1;
                //cout << i<<" "<<j;
            }
        }
    }
    bg[1] = 1;
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<=i;j++){
            if(dp[j][i] == 1){
                bg[i] = max(bg[j]+1,bg[i]);
            }
        }
    }
    cout << bg[n];
    return 0;
}
