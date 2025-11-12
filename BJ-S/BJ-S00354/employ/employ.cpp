#include<bits/stdc++.h>
using namespace std;
int n,m,lans=0,ans=0,cnt=0,c[105],vis[105],vis2[105];
string s;
void dfs(int p){
    if(p!=0&&s[p-1]=='1'){
        lans++;
    }else if(p!=0){
        cnt++;
    }
    if(p==n){
        if(lans>=m)ans++;
        if(s[p-1]=='1')lans--;
        if(s[p-1]=='0')cnt--;
        return;
    }
    int np=p+1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(c[i]<=cnt){
                vis[i]=1;vis2[i]=1;np++;cnt++;continue;
            }
            vis[i]=1;
            dfs(np);
            vis[i]=0;
        }
    }
    for(int i=0;i<=n;i++){
        if((vis2[i])&&c[i]<=cnt){
            vis[i]=0;vis2[i]=0;cnt--;
        }
    }
    if(s[p-1]=='1'){
        lans--;
    }else{
        cnt--;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}
