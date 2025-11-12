#include<bits/stdc++.h>
using namespace std;
char s[505];
int a[505];
int c[505],vis[505];
const long long mod=998244353;
int n,m,ans;
int sum[505];
void dfs(int dep,int cnt,int y){
	//cout<<dep<<" "<<cnt<<" "<<y<<endl;
    if(dep>n){
        if(cnt>=m){
            ans++;
            ans%=mod;
        }
        return ;
    }
    int last=sum[n]-sum[dep-1];
    if(last<m-cnt){
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=1;
        if(c[i]>y&&a[dep]==1){
            
            dfs(dep+1,cnt+1,y);
        }
        else{
            dfs(dep+1,cnt,y+1);
        }
        vis[i]=0;
    }
    return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    memset(vis,0,sizeof(vis));
    cin>>n>>m;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        a[i]=s[i]-'0';
        sum[i]+=a[i]+sum[i-1];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    if(sum[n]<m){
        cout<<0;
        return 0;
    }
    if(sum[n]==n){
        long long ans=1ll;
        for(int i=2;i<=n;i++){
            ans*=n;
            ans%=mod;
        }
        cout<<ans%mod;
        return 0;
    }
    sort(c+1,c+n+1);
    dfs(1,0,0);
    cout<<ans%mod;
    return 0;
}
