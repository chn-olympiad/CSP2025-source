#include <iostream>
#include <cstring>
using namespace std;

int a[1005],dp[1005][1005],n,k,ans;
int v[1005];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    memset(v,0x3f,sizeof(v));
    cin >> n >> k;
    for (int i = 1;i <= n;++i){
        cin >> a[i];
        dp[i][i] = a[i];
        if (a[i] == k){
            v[i] = min(v[i],i);
        }
    }
    for (int len = 2;len <= n;++len){
        for (int l = 1, r = len;r <= n;++l,++r){
            dp[l][r] = dp[l][r-1]^dp[r][r];
            if (dp[l][r] == k){
                v[l] = min(v[l],r);
            }  
        }
    }
    
    for (int x = 1;x <= n;++x){
        int y = v[x],sum=1;
        if (y == 0x3f3f3f3f) continue;
        for (int t = x+1;t <= n;++t){
            if (v[t] == 0x3f3f3f3f) continue;
            if (t > y){
                sum++;
                y = v[t];
            }
        }
        ans = max(ans,sum);
    }

    cout << ans << '\n';

    fclose(stdin);
    fclose(stdout);
    return 0;
}

