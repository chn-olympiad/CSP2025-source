
#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int dp[1005][1005];
bool z[1005];
bool b[1005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    for(int i = 0;i<n;i++){
        dp[i][i] = a[i];
    }
    for(int i = 2;i<=n;i++){
        for(int j = 0;j<=n-i;j++){
            dp[j][j+i-1] = (dp[j][j+i-2] ^ a[j+i-1]);
        }
    }
    int res = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=n-i;j++){
            if(z[j]) continue;
            if(dp[j][j + i - 1] == k){
                bool is_b = false;
                for(int l = j;l<=j + i -1;l++) if(b[l]) is_b = true;
                if(!is_b){
                    res++;
                    z[j] = true;
                    for(int l = j;l<=j + i -1;l++) b[l] = true;
                }
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
