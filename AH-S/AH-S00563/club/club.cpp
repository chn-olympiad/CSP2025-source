#include<bits/stdc++.h>
using namespace  std;
int n;
int a[10010][3];
int dp[10010][3];
int g[10010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vector <int> xx;
        vector <int> yy;
        int x,y;
        x=y=0;
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][2]==0){
                y++;
                if(a[i][1]==0){
                    x++;
                    xx.push_back(a[i][0]);
                }
                yy.push_back(a[i][1]);
            }
        }
        if(x==n&&y==n){
            sort(xx.begin(),xx.end());
            reverse(xx.begin(),xx.end());
            for(int i=0;i<n/2;i++){
                ans+=xx[i];
            }
            cout<<ans<<endl;
        }else if(y==n){
            for(int i=0;i<n;i++){
                xx.push_back(a[i][0]);
            }
            sort(xx.begin(),xx.end());
            reverse(xx.begin(),xx.end());
            sort(yy.begin(),yy.end());
            reverse(yy.begin(),yy.end());
            int cnt=0,sum=0,cnt1=0,sum1=0;
            for(int i=0;i<n/2;i++){
                cnt+=xx[i];
            }
            for(int i=0;i<n/2;i++){
                sum+=yy[i];
            }
            for(int i=n/2;i<n&&i<(n/2)*2;i++){
                cnt1+=xx[i];
            }
            for(int i=n/2;i<n&&i<(n/2)*2;i++){
                sum1+=yy[i];
            }
            ans=max(sum+cnt1,cnt+sum1);
            cout<<ans<<endl;
        }else if(n==2){
            ans=max(ans,a[0][0]+a[1][1]);
            ans=max(ans,a[0][0]+a[1][2]);
            ans=max(ans,a[0][1]+a[1][0]);
            ans=max(ans,a[0][1]+a[1][2]);
            ans=max(ans,a[0][2]+a[1][1]);
            ans=max(ans,a[0][2]+a[1][0]);
            cout<<ans<<endl;
        }else{
            memset(dp,0,sizeof(dp));
            cin>>n;
            for(int i=0;i<n;i++){
                cin>>a[i][0]>>a[i][1]>>a[i][2];
            }
            for(int i=0;i<3;i++){
                for(int j=0;j<n;j++){
                    for(int k=n/2;k>=1;k--){
                        dp[k][i]=max(dp[k][i],dp[k-1][i]+a[j][i]);
                    }
                }
            }
            memset(g,0,sizeof(g));
            for(int i=1;i<=n/2;i++){
                g[i]=max(g[i],g[i-1]+max(dp[i][0],max(dp[i][1],dp[i][2])));
            }
            for(int i=1;i<=n/2;i++){
                ans+=g[i];
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
