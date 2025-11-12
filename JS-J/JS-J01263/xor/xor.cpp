#include<bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define pii pair<ll,ll>
using namespace std;
const int N = 514514;
namespace Cubber{
    int n, k, a[N], dp[N], sum[N], last[1 << 20];
    bool cmp(pii a, pii b){
        return a.sc < b.sc;
    }
    vector<pii> v;
    void solve(){
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = sum[i-1] ^ a[i];
            int nd = k ^ sum[i];
            if(last[nd]) v.push_back({last[nd]+1, i});
            else if(nd == 0) v.push_back({1, i});
            last[sum[i]] = i;
        }
        sort(v.begin(), v.end(), cmp);
        int now = 0, cnt = 0;
        for(auto p : v) if(p.fr > now){
            ++cnt;
            now = p.sc;
        }
        cout << cnt << "\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    Cubber::solve();
    return 0;
}
//chennie and jiangly bless me