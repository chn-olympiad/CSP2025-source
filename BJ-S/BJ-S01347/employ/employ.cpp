#include<bits/stdc++.h>
using namespace std;
int n,m;
bool s[14];
int c[14];
int p[14];
int cal(){
    int res=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(cnt>=c[p[i]] || !s[i]){
            cnt++;
        }else{
            res++;
        }
    }
    return res;
}
int ans=0;
bool vis[14];
void dfs(int stp){
    if(stp==n+1){
        if(cal()>=m) ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            p[stp]=i;
            dfs(stp+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    char ch;
    for(int i=1;i<=n;i++){
        cin>>ch;
        s[i]=(ch=='1');
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}