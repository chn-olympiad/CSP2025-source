#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
using vint = vector<int>;
using pii = pair<int,int>;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    vint c(n);
    for(int i =0;i<n;i++) cin >> c[i];
    vint f(n);
    iota(f.begin(),f.end(),0);
    int ans  =0;
    do {
        int cnt =0;
        int fail =0;
        for(int i =0;i<n;i++){
            if(c[i] =='0') {
                fail++;
            } else if(c[i] <= fail) {
                fail++
            } else {
                cnt++;
            }
        }
        if(cnt >= m) ans++;
    } next_permutation(f.begin(),f.end())
    cout << ans << endl;
    return 0;
}
