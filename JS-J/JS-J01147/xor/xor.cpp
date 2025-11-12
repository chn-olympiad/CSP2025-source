#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n, k;
int a[maxn];
int s[maxn];
struct Node{
    int l, r;
};
Node tmp[maxn];
int ans;
bool cmp(Node x, Node y){
    if(x.l == y.l)
        return x.r < y.r;
    else
        return x.l < y.l;
}
int cnt = 0;
bool b[maxn];
void dfs(int dep){
    if(dep == cnt + 1){
        int R = 0;
        int cnt1 = 0;
        for(int i = 1; i <= cnt; i++){
            if(!b[i])
                continue;
            if(tmp[i].l <= R)
                return ;
            R = max(R, tmp[i].r);
            cnt1++;
        }
        ans = max(ans, cnt1);
        return ;
    }
    b[dep] = true;
    dfs(dep + 1);
    b[dep] = false;
    dfs(dep + 1);
}
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        s[i] = s[i - 1] ^ a[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            int t = s[i] ^ s[j - 1];
            if(t == k){
                tmp[++cnt].l = j;
                tmp[cnt].r = i;
            }
        }
    }
    sort(tmp + 1, tmp + cnt + 1, cmp);
    dfs(1);
    cout<<ans;
    return 0;
}