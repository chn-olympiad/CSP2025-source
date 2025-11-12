#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int k=0;
int a[1000],ans=0;
int dp[1000];
void dfs(int x){
     if(x==m-k){
        ans++;
        return;
     }
     for(int i=1;i<=n;i++){
        if(dp[i]==0){
            dp[i]=1;
            dfs(x+1);
            dp[i]=0;
        }
     }

}
int main(){
//    freopen("employ3.in","r",stdin);
//    freopen("employ111.out","w",stdout);
     cin>>n>>m;
     cin>>s;
     for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            k++;
        }
     }
     dfs(0);
     cout<<ans%998244353;
return 0;
}
