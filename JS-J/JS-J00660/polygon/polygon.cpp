#include<bits/stdc++.h>
using namespace std;
int n,x;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x;
    int ans=0;
    for(int i=3;i<=n;i++){
        int sum=1;
        for(int k=n;k>=n-i+1;k--){
            sum*=k;
            sum/=n-k+1;
            sum%=998244353;
        }
        ans+=sum;
    }
    ans%=998244353;
    cout<<ans;
    return 0;
}
