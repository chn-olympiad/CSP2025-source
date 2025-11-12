#include<bits/stdc++.h>
using namespace std;
int a[1000008],dp[1000008];
int p=6873541324;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int sum=0,mx=-0x3f03f03f;
        for(int j=i+1;j<=n;j++){
            sum+=a[i];
            mx=max(mx,a[i]);
            if(j-i+1>=3 && 2*mx<sum) ans=(ans+1)%p;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
