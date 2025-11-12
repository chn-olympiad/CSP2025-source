#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010] = {};
int ans = 0;
struct node{
int x;
int sum;
int ma;
int dp;
};
void dfs(node m){
    if(m.sum > m.ma * 2 and m.dp >= 3)ans = (ans + 1)%998244353;
    if(m.x < n){
        node t = {m.x + 1, m.sum + a[m.x], max(m.ma, a[m.x]),m.dp + 1};
        dfs(t);
        node t2 = {m.x + 1, m.sum, m.ma,m.dp};
        dfs(t2);
    }
    return;
}
queue<node> q;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    dfs({1,a[0],a[0],1});
    cout << ans;
return 0;
}
