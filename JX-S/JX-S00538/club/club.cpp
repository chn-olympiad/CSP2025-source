#include<bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define xx first
#define yy second
#define ll long long
const int N = 1e5 + 10;
int T, n, c[4];
PII x[4];
vector<int> v[4];
ll ans;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while(T --){
        ans = 0;
        v[1].clear(), v[2].clear(), v[3].clear();
        c[1] = c[2] = c[3] = 0;
        cin >> n;
        for(int i = 1; i <= n; i ++){
            cin >> x[0].xx >> x[1].xx >> x[2].xx;
            x[0].yy = 1, x[1].yy = 2, x[2].yy = 3;
            sort(x, x + 3);
            c[x[2].yy] ++;
            v[x[2].yy].push_back(x[2].xx - x[1].xx);
            ans += x[2].xx;
        }
        int pos = 0;
        for(int i = 1; i <= 3; i ++){
            sort(v[i].begin(), v[i].end());
            if(c[i] > n / 2)pos = i;
        }
        if(pos){
            c[pos] -= n / 2;
            for(int i = 0; i < c[pos]; i ++)ans -= v[pos][i];
        }
        cout << ans << '\n';
    }
    return 0;
}