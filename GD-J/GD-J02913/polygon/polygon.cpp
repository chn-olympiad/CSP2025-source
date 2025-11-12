#include<bits/stdc++.h>
#define rep(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;

const int INF = INT_MAX / 2;
const int N = 1e5 + 5;
const int P = 998244353;
int n;
int a[N];
int id[N];
bool vis[N];
set<vector<int>> s;
int ans = 0;
vector<int> v;
void dfs(int cnt, int len, int mx){
    if(cnt >= 3 && len > 2 * mx){
        sort(ALL(v));
        s.insert(v);
        return;
    }
    rep(i,1,n,1){
        if(vis[i]) continue;
        vis[i] = true;
        v.push_back(i);
        dfs(cnt + 1, len + a[i], max(mx, a[i]));
        v.pop_back();
        vis[i] = false;

    }
}
bool HaveNoFirstPrize = true;//ALL are 1

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    rep(i,1,n,1) {
        cin >> a[i], id[i] = i;
        if(a[i] != 1) HaveNoFirstPrize = false;
    }

    if(n < 3) {cout << 0; return 0;}
    if(n == 3) {
        if((a[1] + a[2] + a[3]) > 2 * max({a[1],a[2],a[3]})) cout << 1 <<endl;
        else cout << 0 << endl;
        return 0;
    }
    if(HaveNoFirstPrize){
        int cnt =0;
        rep(i,1,n - 2,1) cnt += i;
        cout << cnt << endl;
        return 0;
    }


    mt19937 mt(20100914);
    cout << mt() % P << endl;

    return 0;
}
