#include<bits/stdc++.h>
using namespace std;
char a[100005];
int t[100005];
int n,m;
int vis[100005];
int v[100005];
int ans=0;
void dfs(int cur){
    if(cur>n){
        int cnt=0;
        int r=0;
        for(int i=1;i<=n;i++){
            //cout<<r<<" ";
            int c=vis[i];
            if(t[c]>r&&a[i]=='1'){
                cnt++;
            }else{
                r++;
            }
        }
        //cout<<endl;
        if(cnt>=m){
            ans++;
            ans=ans%998244353;
        }
        //cout<<endl;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!v[i]){
            vis[cur]=i;
            v[i]=1;
            dfs(cur+1);
            v[i]=0;
        }
    }
}
int main (){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
