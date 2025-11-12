#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin >> n >> m;
    long long ans = 1;
    for(int i = 2; i <= n; i++)ans=ans*n%998244353;
        cout << ans << endl;
    return 0;
}
//0~25pts
//sum:141~203pts