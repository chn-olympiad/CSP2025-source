#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 1; i <= n; i++)
using namespace std;
const int N = 5e5 + 10, INF = 9e18;
int n, k, cnt;
int a[N];
set<int> st;
signed main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    rep(i, n){
        st.clear();
        int sum(0);
        for(int j = i; j <= n; j++){
            sum ^= a[j];
            if(st.find(k ^ sum) != st.end() || sum == k){
                i = j;
                cnt++;
                break;
            }
            //cout << sum << ' ';
            st.insert(sum);
        }
    }
    cout << cnt;

    return 0;
}
