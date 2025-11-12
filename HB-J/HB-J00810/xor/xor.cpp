#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],ans,s[500005];
bool b[500005];
bool check(int l,int r) {
    for(int i=l; i<=r; i++)
        if(b[i] == 1) return 0;
    return 1;
}
void dfs(int l, int r) {
    if(l > r) return ;
    if(l > n || r > n) return ;
//    cout << l << " " << r << endl;
    bool f = 0;
    for(int i=l; i<=r; i++) {
        if(a[i] == k) {
            f = 1;
            ans++;
            b[i] = 1;
            dfs(l,i-1);
            l = i+1;
        }
    }
    if(f) dfs(l,r);
    else {
        for(int i=l; i<r; i++) {
            for(int j=i+1; j<=r; j++){
                int yhh;
                if(i == 1) yhh = s[j];
                else yhh = s[j] ^ s[i-1];
                if(yhh == k && check(i,j)) {
                    ans++;
                    for(int k=i ;k<=j ;k++) b[k] = 1;
                }
            }
        }
    }
    return ;
}
signed main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i=1; i<=n ;i++) cin >> a[i];
    s[1] = a[1];
    for(int i=2; i<=n ;i++) s[i] = s[i-1] ^ a[i];
    dfs(1,n);
    cout << ans;
    return 0;
}
