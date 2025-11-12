#include<bits/stdc++.h>
using namespace std;

const int N = 1E6 + 10;
int n, k;
int a[N];
int ans = INT_MIN;
struct s{
    int st;
    int nd;
};
vector<s> vec[N];
int cnt_value(int st, int nd){
    int sum = a[st];
    for(int i = st + 1;i <= nd;i++){
        sum ^= a[i];
    }
    return sum;
}
int t;
void dfs(int i, bool have, int st, int tot){
    t = max(t, tot);
    if(i > n){
        return ;
    }
    if(have || i == n){
        vec[tot].push_back({st, i});
        dfs(i + 1, false, -1, tot + 1);
    } else {
        vec[tot].push_back({i, i});
        dfs(i + 1, false, -1, tot + 1);

        dfs(i + 1, true, i, tot);
    }
    dfs(i + 1, false, -1, tot);
}
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    bool f = true;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != 1){
            f = false;
        }
    }
    if(f){
        cout << n / 2;
        return 0;
    }
    for(int i = 1;i <= t;i++){
        bool f = true;
        for(int j = 0;j < (int)vec[i].size();j++){
            int start = vec[i][j].st;
            int ed = vec[i][j].nd;
            cout << start << ' ' << ed << ",";
            if(cnt_value(start, ed) != k){
                f = false;
                break;
            }
        }
        cout << "\n";
        if(f){
            ans = max(ans, (int)vec[i].size());
        }
    }
    dfs(1, false, -1, 0);
    cout << ans;
    return 0;
}
