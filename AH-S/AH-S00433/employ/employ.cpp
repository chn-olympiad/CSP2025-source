#include<bits/stdc++.h>
using namespace std;
const int N=110;
const int MOD=998244353;
int n,m,ans;
int c[N];
string s;
int vis[N],a[N],num[N];
bool check(){
    int res=0;
    for(int i=1;i<=n;i++){
        a[i]=c[num[i]];
    }
    int p=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='0')p++;
        if(s[i]=='1'){
            if(a[i]<=p)p++;
            else res++;
        }
    }
    if(res>=m)return 1;
    else return 0;
}
void dfs(int t){
    if(t>n){
        if(check())ans++;
        ans%=MOD;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        num[t]=i;
        vis[i]=1;
        dfs(t+1);
        num[t]=0;
        vis[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++)cin>>c[i];
    dfs(1);
    cout<<ans<<"\n";
    return 0;
}
