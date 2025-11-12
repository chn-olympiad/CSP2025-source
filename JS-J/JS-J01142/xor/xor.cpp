#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll num = 0,sign = 1;char ch = ' ';
    while(ch < '0' || ch > '9') sign = (ch == '-' ? -1 : 1),ch = getchar();
    while(ch >= '0' && ch <= '9') num = (num << 3) + (num << 1) + ch - '0',ch = getchar();
    return sign == 1 ? num : -num;
}
ll a[500010],n,k,ans,a1,a0;
void dfs(ll t,ll xo,ll sum){
    ans = max(ans,sum);if(t > n) return ;
    if((xo ^ a[t]) == k){dfs(t + 1,0,sum + 1);}
    else dfs(t + 1,xo ^ a[t],sum);
    dfs(t + 1,xo,sum);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n = read();k = read();
    for(int i = 1;i <= n;i++){
        a[i] = read();
        if(a[i] == 1) a1++;
        if(a[i] == 0) a0++;
    }
    if(a1 == n && k == 0){cout << n / 2 << '\n';return 0;}
    if(a1 + a0 == n){
        if(k == 1) cout << a1 << '\n';
        if(k == 0){
            ll x;
            for(int i = 1;i <= n;i++){
                if(a[i]) x++;
                if(!a[i]){a0 += x / 2;x = 0;}
            }
            cout << a0 + x / 2 << '\n';
        }
        return 0;
    }
    dfs(1,0,0);
    cout << ans << '\n';
    return 0;
}
