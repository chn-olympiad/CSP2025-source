#include <iostream>
#include<vector>
using namespace std;
int n,m,vis[100001],nai[100001];//,dp[100001];
string a;
/*
int dfs(int person,int failed){
    if(person-failed<m)return -1;
    if(dp[person][failed])return dp[person][failed];
    int cnt=0;
    for(int i=1;i<=n;i++){
        
    }
}
*/
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>a;
    for(int i=1;i<=n;i++){
        cin>>nai[i];
    }
    a=" "+a;
    int cnt1=0;
    for(int i=1;i<=n;i++){
        if(a[i]==1)cnt1++;
    }
    if(m>cnt1)cout<<0;
    else{
        long long ans=1;
        for(long long i=2;i<=m;i++){
            ans*=i;
            ans=ans%998244353;
        }
        cout<<ans;
    }
    return 0;
}
