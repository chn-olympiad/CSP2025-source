#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10,md = 998244353;
int n,m,c[N],vis[N];
int dp[(1<<18)+5][20];
long long ans;
char s[N];
void dfs(int x,int cnt,int num){
    if(cnt==n){
        if(num<=n-m){
            ans++;
            ans=ans%md;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            if(num>=c[i]){
                dfs(i,cnt+1,num+1);
                vis[i]=0;
            }
            else if(s[cnt+1]=='0'){
                dfs(i,cnt+1,num+1);
                vis[i]=0;
            }
            else{
                dfs(i,cnt+1,num);
                vis[i]=0;
            }
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(n<=10){
        dfs(0,0,0);
        cout<<ans<<endl;
    }
    else if(n<=18){
        dp[0][0]=1;
        for(int i=0;i<(1<<n);i++){
            int now=i,tot=0;
            while(now){
                if(now&1) tot++;
                now=now>>1;
            }
            for(int j=1;j<=n;j++){
                int tmp=(1<<j)&i;
                if(tmp==0){
                    for(int k=0;k<=tot;k++){
                        if(k>=c[j]){
                            long long f=((long long)dp[i+(1<<j)][k+1]%md+(long long)dp[i][k]%md)%md;
                            dp[i+(1<<j)][k+1]=f;
                        }
                        else if(s[tot+1]=='0'){
                            long long f=((long long)dp[i+(1<<j)][k+1]%md+(long long)dp[i][k]%md)%md;
                            dp[i+(1<<j)][k+1]=f;
                        }
                        else{
                            long long f=((long long)dp[i+(1<<j)][k]%md+(long long)dp[i][k]%md)%md;
                            dp[i+(1<<j)][k]=f;
                        }
                    }
                }
            }
        }
        for(int i=0;i<=n-m;i++){
            ans=(ans%md+(long long)dp[(1<<n)-1][i]%md)%md;
        }
        cout<<ans<<endl;
    }
    return 0;
}
