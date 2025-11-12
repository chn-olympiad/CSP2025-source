#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=505,INF=998244353;
bool vis[N];
LL a[N],c[N],n,m,ans;
void dfs(LL cur,LL cnt0,LL cnt1){
    if(cur>n&&cnt1>=m){
        ans++;
        ans%=INF;
        return ;
    }
    for(LL i=1;i<=n;i++){
        if(!vis[i]&&cnt0<c[i]){
            vis[i]=true;
            if(a[cur]==0){
                dfs(cur+1,cnt0+1,cnt1);
            }
            else{
                dfs(cur+1,cnt0,cnt1+1);
            }
            vis[i]=false;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    char ch;
    bool fa=true;
    LL cnt0=0;
    cin>>n>>m;
    for(LL i=1;i<=n;i++){
        cin>>ch;
        if(ch=='0') fa=false;
        a[i]=ch-'0';
    }
    for(LL i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0){
            cnt0++;
        }
    }
    if(fa){
        ans=1;
        for(LL i=1;i<=m;i++){
            ans*=(n-cnt0-i+1);
            ans%=INF;
        }
        cout<<ans%INF;
        return 0;
    }
    dfs(1,0,0);
    cout<<ans%INF;
    return 0;
}
