#include <bits/stdc++.h>
using namespace std;

const int mod =     998244353;
int n, m;   
namespace solve15{
    const int N = 20, M = (1<<18);
    int f[M][N];
    string s;
    int c[N];
    int popcount(int x){
        int cnt = 0;
        while (x){
            cnt += x % 2;
            x >>= 1;
        }
        return cnt;
    }
    void run(){
        cin >> s;
        for (int i = 0; i < n; i++)
            cin >> c[i];
        f[(1 << n) - 1][0] = 1;
        for (int i = (1 << n) - 1; i >= 0; i--)
            for (int j = 0; j <= n; j++)
                if (f[i][j])
                    for (int k = 0; k < n; k++)
                        if (i & (1 << k)){
                            int newmask = i ^ (1 << k);
                            int now = j;
                            if (s[n - popcount(i)] == '0' || j >= c[k])now++;
                            (f[newmask][now] += f[i][j]) %= mod;
                            // cout << i << ' ' << j << "->" << newmask << ' ' << now << ' ' << f[newmask][now] << endl;
                        }
        int ans = 0;
        for (int i = 0; i <= n; i++)
            if (n - i >= m)
                (ans += f[0][i]) %= mod;
        cout << ans;
    }
};
int main(){
    freopen("employ.in", "r", stdin);    
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    if (n <= 18){
        solve15::run();
        return 0;
    }
    return 0;
}