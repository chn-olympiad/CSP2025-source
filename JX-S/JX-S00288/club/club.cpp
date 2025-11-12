#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[100005][5];
int b[5];
int ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(a,sizeof(a),0);
        memset(b,sizeof(b),0);
        cin>>n;
        if(n==100000){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=3;j++){
                    cin>>a[i][j];
                }
            }
            int b[100005];
            for(int i=1;i<=n;i++) b[i]=a[i][1];
            sort(b+1,b+n+1);
            for(int i=n;i>=n/2;i--){
                ans+=b[i];
            }
            cout<<ans<<endl;
        }
        else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        int s=n/2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                if(b[j]<=s){
                    dp[i][j]=max(dp[i][j-1],a[i][j]);
                }
            }
            ans+=dp[i][3];
        }
        cout<<ans<<endl;
        }
}
