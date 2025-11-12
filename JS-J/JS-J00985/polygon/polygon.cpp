#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10;
int a[N], n, mx, idx=0, b[20], cnt;
bool vis[20];
void dfs(int n, int step, int i){
    if(step>n+1) return;
    if(step>3){
        int maxn=0, sum=0;
        for(int i=1;i<=step;i++){
            maxn=max(maxn, b[i]);
            sum+=b[i];
        }
        if(maxn*2<sum) cnt++;
    }
    for(int j=i;j<=n;j++){
        if(!vis[j]){
            b[step]=a[j];
            vis[j]=1;
            dfs(n, step+1, j+1);
            vis[j]=0;
        }
    }
}
bool check1(){
    for(int i=1;i<=n;i++) mx=max(mx, a[i]);
    return mx<=1;
}
void solve1(){
    int ans=0, m=0;
    for(int i=1;i<=n;i++) if(a[i]==1) m++;
    for(int i=3;i<=m;i++){
        int t=1;
        for(int j=0;j<i;j++) t*=(m-j);
        ans+=t;
    }
    cout << ans;
    return;
}
void solve2(){
    int sum=0, cnt=0;
    for(int i=1;i<=n;i++) sum+=a[i];
    dfs(n, 1, 1);
    cout << cnt;
    return;
}
signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(check1()) solve1();
    else if(n<=3){
        int x=a[1]+a[2]+a[3], y=max({a[1], a[2], a[3]});
        if(x>2*y) cout << 1;
        else cout << 0;
    }else solve2();
    return 0;
}
