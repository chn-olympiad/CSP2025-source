#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int n,k,a[N + 5],c1,c0,ma,ans,cnt;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] == 1)
            c1++;
        else if(a[i] == 0)
            c0++;
        ma = max(ma,a[i]);
    }
    if(k > ma){
        cout << 0 << '\n';
        return 0;
    }
    if(k == 1){
        cout << c1 << '\n';
    }
    else if(k == 0){
        ans = c1 / 2 + c0;
        cout << ans << '\n';
    }
    else
        cout << 0 << '\n';
    return 0;
}
