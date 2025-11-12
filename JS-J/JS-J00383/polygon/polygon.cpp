#include <bits/stdc++.h>
using namespace std;
const int N = 5005,P = 998244353;
typedef long long ll;
ll ans,n,a[N];
bool use[N];

void dfs(int w){
    if (w == n + 1){
        ll maxn = -1,sum = 0,g = 0;
        for (int i = 1;i <= n;i++){
            if (use[i]){
                maxn = max(maxn,a[i]);
                sum += a[i];
                g++;
            }
        }
        if (sum > maxn * 2 && g >= 3){
            ans += 1;
            ans %= P;
        }
    }else{
        dfs(w + 1);
        use[w] = 1;
        dfs(w + 1);
        use[w] = 0;
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    dfs(1);

    cout << max(ans,0 * 1ll);
    return 0;
}
