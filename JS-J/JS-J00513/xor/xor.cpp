#include<bits/stdc++.h>
using namespace std;
//#define int long long
int ans = 0;
int hmn = 0;
int n,k,a[5005],sum[5005],pos[5005];
void dfs(int t,int cnt){
    hmn ++;
    if(t > n){
        ans = max(ans,cnt);
        return ;
    }
    if(pos[t] != 0){
        int q = pos[t];
        dfs(q+1,cnt + 1);
    }
    dfs(t+1,cnt);
    return ;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    sum[0] = 0;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        sum[i] = sum[i-1] ^ a[i];
    }
    for(int i = 1;i <= n;i ++){
        int now = sum[i-1]^k;
        for(int j = i;j <= n;j ++){
            if(sum[j] == now){
                pos[i] = j;
                break ;
            }
        }
        //cout << i << " " << pos[i] << " " << now << endl;
    }
    dfs(1,0);
    cout << ans << " " << hmn;
    return 0;
}
