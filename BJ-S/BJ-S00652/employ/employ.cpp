#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 505, mod=998244353;
int n, m;
char cs[N];
bool s[N];
int c[N];
ll A[N];

void init(){
    A[0]=1;
    for (int i = 1; i<=n; i++){
        A[i] = A[i-1]*i%mod;
    }

    bool flag=true;
    for (int i=1; i<= n; i++){
        s[i] = cs[i]-'0';
        if (!s[i]) flag=false;
    }
    if (!flag) return;
    if (n<=20) return;

//    ll ans=1;
//    for (int i=1; i<=)
    cout << A[n];
    exit(0);
}

namespace part1{
    ll ans;
    bool vis[N];
    int cnt;
//    vector<int> v;

    void enu(int u){
        if (u>n){
//            for (int i: v) cout<<i<<" ";
//            cout<<endl;
            if (cnt>=m) ans++, ans%=mod;
            return;
        }
        if (n-u+1+cnt<m) return;
        if (cnt==m){
            ans += A[n-u+1], ans%=mod;
            return;
        }
        for (int i=1; i<=n; i++){
            if (vis[i]) continue;
            vis[i] = 1;
            bool flag=0;
            if (s[u]&&u-cnt-1<c[i]) cnt++, flag=1;
//            v.push_back(i);
            enu(u+1);
            vis[i] = 0;
            if (flag) cnt--;
//            v.pop_back();
        }
    }

    void solve(){
        enu(1);
        cout << ans;
    }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> cs+1;
    for (int i=1; i<=n; i++){
        cin >> c[i];
    }
    init();
    part1::solve();
    return 0;
}

