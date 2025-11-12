#include<bits/stdc++.h>
using namespace std;
int dp[55][55][55][55];
struct luo{
    int b[5];
    int c;
}a[100005];
bool cmp1(luo a,luo b){
    return a.c>b.c;
}
bool cmp2(luo a,luo h){
    return a.b[1]<h.b[1];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        long long ans=0;
        cin>>n;
        bool flag1=1,flag2=1;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].b[1],&a[i].b[2],&a[i].b[3]);
            a[i].c=a[i].b[1]-a[i].b[2];
            if(a[i].b[3]!=0) flag1=0;
            if(a[i].b[2]!=0||a[i].b[3]!=0) flag2=0;
        }
        if(flag1==1){
            sort(a+1,a+n+1,cmp1);
            for(int i=1;i<=n/2;i++){
                ans+=a[i].b[1];
                ans+=a[i+n/2].b[2];
            }
            cout<<ans<<endl;
            continue;
        }
        if(flag2==1){
            sort(a+1,a+n+1,cmp2);
            for(int i=n/2+1;i<=n;i++) ans+=a[i].b[1];
            cout<<ans<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int k1=0;k1<=n/2;k1++){
                for(int k2=0;k2<=n/2;k2++){
                    for(int k3=0;k3<=n/2;k3++){
                        if(k1+k2+k3>n) break;
                        if(k1+k2+k3>i) break;
                        dp[i][k1][k2][k3]=dp[i-1][k1][k2][k3];
                        if(k1>0) dp[i][k1][k2][k3]=max(dp[i][k1][k2][k3],dp[i-1][k1-1][k2][k3]+a[i].b[1]);
                        if(k2>0) dp[i][k1][k2][k3]=max(dp[i][k1][k2][k3],dp[i-1][k1][k2-1][k3]+a[i].b[2]);
                        if(k3>0) dp[i][k1][k2][k3]=max(dp[i][k1][k2][k3],dp[i-1][k1][k2][k3-1]+a[i].b[3]);
                        ans=max(ans,(long long)dp[i][k1][k2][k3]);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
