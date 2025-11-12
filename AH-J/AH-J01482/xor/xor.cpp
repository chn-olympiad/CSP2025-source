//AH-J01482 Eason Cyj001001
#include "bits/stdc++.h"
#define int long long

using namespace std;

bool flag = true;
int cnt1;
int summ;
const int N = 5e5 + 10;
int n,k;
int a[N];
int dp[1005][1005];
int sum[N];
int l,r,cnt;

signed main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        sum[i] = (sum[i-1] ^ a[i]);
        if(a[i] >= 2) flag = false;
        else {
            if(a[i] == 1) {
                cnt1++;
            }
        }
    }
    if(flag) {
        cout << cnt1/2;
    }else{
        memset(dp,-1,sizeof(dp));
        for(int i=1; i<=n; i++) {
            dp[i][i] = a[i];
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(dp[i][j] == -1)dp[i][j] = (sum[i] ^ sum[j]);
            }
        }
        for(int i=1; i<=n; i++) {
            l=r=1;
            while(r<=n) {
                while(r<=n && dp[l][r++] != k);
                if(n+1 == r) break;
                l=r+1,r++;
                cnt++;
            }
            summ = max(summ,cnt);
            cnt=0;
        }
    }
    cout << summ;
    return 0;
}
