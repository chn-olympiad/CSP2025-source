#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long dp[5005][5005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n,cmp);
    for (int i=0;i<n-2;i++){
        for (int j=i+1;j<n-1;j++){
            for (int k=j+1;k<n;k++){
                if (a[i]<a[j]+a[k]) dp[i][k]++;
            }
        }
    }
    for (int i=n-3;i>=0;i--){
        for (int j=i+2;j<n;j++){
            for (int k=i;k<=j-3;k++){
                dp[i][j]+=dp[k][j-1]*2;
            }
        }
    }
    cout << dp[0][n-1]%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
