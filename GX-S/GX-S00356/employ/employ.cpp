#include<bits/stdc++.h>
using namespace std;
int n,m,a[10100],rans,len;
bool vis[10100]={false},fail[10100];
string b;
void dfs(int s,int ans,int day){
    vis[s] = true;bool flag = true;

    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            flag = false;
            break;
        }
    }
    if(flag||day==n-1){
        if(ans>=m){
            rans++;
        }
        return;
    }
    if(b[day]=='0'){
        for(int i=1;i<=n;i++){
            fail[i]++;
            if(fail[i]>=a[i]) vis[i] = true;
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==false){
                dfs(i,ans,day+1);
            }
        }
    }else{
        for(int i=1;i<=n;i++){
            if(vis[i]==false) dfs(i,ans+1,day+1);
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    cin>>b;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    len = b.size();
    for(int i=1;i<=n;i++){
        dfs(i,0,0);
        memset(vis,false,sizeof(vis));
        memset(fail,0,sizeof(fail));
    }
    cout<<rans;
    return 0;
}
