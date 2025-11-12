//remember:
//freopen!!!
//mod!!!
//time limit and memory limit!!!
//the special numbers!!!

#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
using namespace std;
const int N=510;
int n,m,ans;
int f[N],a[N],c[N];
bool vis[N];
void dfs(int now){
    if(now==n+1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(cnt>=c[f[i]]||a[i]==1)
                cnt++;
        }
        if(n-cnt>=m)
            ans++;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            f[now]=i;
            vis[i]=1;
            dfs(now+1);
            vis[i]=0;
        }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=s.size();i++)
        a[i]=s[i-1]=='0';
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n;i++)
        f[i]=i;
    dfs(1);
    cout<<ans;
    return 0;
}
