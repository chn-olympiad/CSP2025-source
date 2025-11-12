#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 5e5 + 7;
int n, k, ans, a[N];
bool vis[N];
void dfs(int now, stack<int> &st){
    int sum = 0;
    vector<int> v;
    while(!st.empty()){
        sum ^= st.top();
        v.push_back(st.top());
        st.pop();
    }
    if(sum == k){
        ans++;
        return ;
    }
    for(auto i : v){
        st.push(i);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            st.push(a[i]);
            vis[i] = true;
            dfs(a[i], st);
            vis[i] = false;
            st.pop();
        }
    }
}
signed main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    bool f = true;
    for(int i = 1; i <= n; i++) if(a[i] != 1) f = false;
    if(f && (k == 0)){
        cout << n / 2 << '\n';
        return 0;
    }
    for(int i = 1; i <= n; i++){
        stack<int> s;
        dfs(i, s);
    }
    cout << ans << '\n';
    return 0;
}
