#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
const int mod = 998244353;
bool s[N];
int c[N], a[N];
int mp[N];
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        char c;
        cin >> c;
        s[i] = c - '0';
    }
    for (int i = 1;i <= n;i++){
        cin >> c[i];
        mp[i] = c[i];
    }
    for (int i = 1;i <= n;i++){
        a[i] = i;
    }
    int ans = 0;
    do{
        int tot = 0, cnt = 0;
        for (int i = 1;i <= n;i++){
            if (!s[i] || tot >= mp[a[i]]) tot++;
            else cnt++;
        }
        ans = (ans + (cnt >= m)) % mod;
    }while (next_permutation(a + 1, a + n + 1));
    cout << ans;
    return 0;
}
