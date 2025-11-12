#include<bits/stdc++.h>
using namespace std;
const int N=20;
int ans,n,m,a[N],b[N];
bool vis[N];
string s;
bool chk(){
    int sum=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(sum>=a[b[i]]) sum++;
        else{
            if(s[i]=='0') sum++;
            else cnt++;
        }
    }
    if(cnt>=m) return true;
    else return false;
}
void dfs(int cur){
    if(cur==n+1){
        if(chk()==true) ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]!=true){
            b[cur]=i;
            vis[i]=true;
            dfs(cur+1);
            vis[i]=false;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s=' '+s;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1);
    cout<<ans;
    return 0;
}
