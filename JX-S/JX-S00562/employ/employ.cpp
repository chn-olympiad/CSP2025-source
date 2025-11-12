#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,m,c[505],zhu[505][505];

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 1;i<=n;i++){
        cin >> c[i];
    }
    long long ans = 1;
    zhu[1][1] = zhu[2][1] = zhu[2][2] = 1;
    for(int i = 3;i<=504;i++){
        for(int j = 1;j<=i;j++){
            zhu[i][j] = zhu[i-1][j] + zhu[i][j-1];
        }
    }
    for(int i = 1;i<=n;i++){
        ans *= zhu[i][i];
    }
    cout << ans;

    return 0;
}
