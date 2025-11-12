#include <bits/stdc++.h>
using namespace std;

int a[500010];
int s[500010];
int dp[500010];
int mx[500010];
unordered_map<int,int>mp;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=n;i++){
        s[i]=a[i]^s[i-1];
    }

    dp[0]=0;
    int ans=0;
    for (int i=1;i<=n;i++){
        dp[i]=0;
        if (mp[m^s[i]]!=0){
            dp[i]=mx[mp[m^s[i]]]+1;
        }
        if (s[i]==m){
            dp[i]=max(dp[i],1);
        }
        mp[s[i]]=i;
        ans=max(ans,dp[i]);
        mx[i]=max(mx[i-1],dp[i]);
    }
    printf("%d",ans);
    return 0;
}

