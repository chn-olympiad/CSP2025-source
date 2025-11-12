#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[510],is[510],a[510],vis[510];
int ans;
bool check() {
    int cnt=0,fall=0;
    for(int i=1;i<=n;i++) {
        if(fall>=c[a[i]]) {
            fall++;
            continue;
        }
        if(is[i]==1) {
            cnt++;
        } else {
            fall++;
        }
    }
    if(cnt>=m) {
        return true;
    } else {
        return false;
    }
}
void dfs(int num) {
    if(num>=n) {
        if(check()) {
            ans=(ans+1)%998244353;
            return;
        }
    }
    for(int i=1;i<=n;i++) {
        if(vis[i]==0) {
            vis[i]=1;
            a[num]=i;
            dfs(num+1);
            a[num]=0;
            vis[i]=0;
        }
    }
    return;
}
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<s.size();i++) {
        is[i+1]=s[i]-'0';
    }
    for(int i=1;i<=n;i++) {
        cin>>c[i];
    }
    dfs(1);
    cout<<ans%998244353;
    return 0;
}