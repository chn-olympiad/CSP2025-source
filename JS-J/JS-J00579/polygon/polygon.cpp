#include<bits/stdc++.h>
using namespace std;

const long long NP=5e3+10,AP=5e3+10,Mod=998244353;
int l[NP];
long long n,dp[AP],ans=0;

int limit(long long x){
    if(x<=(int)5e3) return x;
    else return 5e3+5;
}

int main(){
    memset(dp,0,sizeof(dp));

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    sort(l+1,l+n+1);

    if(n==3){
        cout<<((l[1]+l[2]+l[3])>(max({l[1],l[2],l[3]})*2));
        return 0;
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=int(5e3)+1;j>=0;j--){
            if(dp[limit(j)]==0) continue;
            if(j>l[i]){
                ans=(ans+dp[limit(j)])%Mod;
            }
            dp[limit(j+l[i])]=(dp[limit(j+l[i])]+dp[limit(j)])%Mod;
        }
    }
    cout<<ans;
    return 0;
}
