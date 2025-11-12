#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500+5;
const int mod=998244353;
int n,m;
int a[N],s[N];
int c[N];
bool vis[N];
int ans=0;
void dfs(int pl,int cnt){
    if (pl>n){
        //cout<<cnt<<'\n';
        if (cnt>=m) ans++;
        return;
    }
    if (cnt+n-pl+1<m) return;
    for (int i=1;i<=n;i++){
        if (vis[i]) continue;
        vis[i]=1;
        int d=0;
        if (a[i]==1&&s[pl]<c[i]) d=1;
        dfs(pl+1,cnt+d);
        vis[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    bool flag=1;
    for (int i=1;i<=n;i++){
        char ch;
        cin>>ch;
        a[i]=ch-48;
        s[i]=s[i-1]+1-a[i];
        flag=flag&&a[i];
        //cout<<s[i]<<' ';
    }
    int cnt=0;
    for (int i=1;i<=n;i++){
        cin>>c[i];
        if (c[i]>0) cnt++;
    }
    if (flag){
        if (cnt<m) cout<<0<<'\n';
        else{
            ll res=1;
            for (int i=1;i<=n;i++){
                res=res*i%mod;
            }
            cout<<res<<'\n';
        }
    }
    else{
        dfs(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}
