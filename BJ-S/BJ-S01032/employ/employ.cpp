#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n,m,c[505],vis[505],t=0,ans[505],maxans=0;
string s;
void dfs(int x,int y){
    //cout<<x<<' '<<y<<endl;
    ans[x]=y;
    vis[y]=1;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        dfs(x+1,i);
    }
    vis[y]=0;
    if(x==n){
        int p=0;
        for(int i=0;i<n;i++){
            //cout<<ans[i+1]<<' ';
            int cnt=0;
            if(s[i]=='1') p++;
            for(int j=0;j<i;j++)
                cnt+=s[j]-'0';
            if(c[ans[i+1]]<=cnt){
                s[i]='0';
                p--;
            }
        }
        //cout<<endl;
        if(p>=m) maxans++;
        return;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    dfs(0,0);
    cout<<maxans<<endl;
    return 0;
}
