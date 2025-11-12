#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
int a[N],b[N],c[N],dp[N];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int m=n/2;
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                dp[j]=max(dp[j],dp[j-1]+a[i]);
            }
        }
        cout<<dp[m]<<endl;
    }
    return 0;
}
