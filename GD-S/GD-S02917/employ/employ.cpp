#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
ll t[21000];
ll a[21000];
ll vis[21000];
ll ans;
string s;
void dfs(int x,int sum,int f){
    if(x>n){
        if(sum>=k)ans++;
        ans%=998244353;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==1)continue;
        if(t[x]==0||f>=a[i]){
            vis[i]=1;
            dfs(x+1,sum,f+1);
            vis[i]=0;
        }else{
            vis[i]=1;
            dfs(x+1,sum+1,f);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>k>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<n;i++)t[i+1]=(s[i]-'0');
    dfs(1,0,0);
    cout<<ans%998244353;
    return 0;
}