#include<bits/stdc++.h>
using namespace std;
#define please return
#define AC 0
int n,m,s[500005],k[500005],ans;
void dfs(int sum,int now){
    if(now>n){
        ans=max(sum,ans);
        return;
    }
    if(ans-sum>=now)return;
    int i;
    bool f=false;
    for(i=now;i<=n;i++){
        if((k[i]^k[now-1])==m){
            f=true;
            break;
        }
    }
    if(f==true)dfs(sum+1,i+1);
    dfs(sum,now+1);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)k[i]=k[i-1]^s[i];
    dfs(0,1);
    cout<<ans;
    please AC;
}
