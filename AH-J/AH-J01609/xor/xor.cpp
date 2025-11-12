#include<bits/stdc++.h>
using namespace std;
int n,k,t,maxx;
int a[500005],dp[500005];
int xor_find(int x,int y){
    int t=1,ans=0;
    while(x!=0||y!=0){
        if(x%2!=y%2)ans+=t;
        x/=2;y/=2;t*=2;
    }
    return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            if(j==i)t=a[j];
            else t=xor_find(t,a[j]);
            if(t==k){
                if(j==1)dp[i]=max(dp[i],1);
                else{
                    for(int k=1;k<=j-1;k++){
                        dp[i]=max(dp[i],dp[k]+1);
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        maxx=max(maxx,dp[i]);
    }
    cout<<maxx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
