#include <bits/stdc++.h>
using namespace std;
int t;
int a[100005][4];
int d[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>a[i][j];
        if(n==2){
            int ans=0;
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    if(i!=j) ans=max(ans,a[1][i]+a[2][j]);
                }
            }
            cout<<ans<<endl;
        }
        else if(n==4){
            int ans=0;
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    for(int k=1;k<=3;k++){
                        for(int l=1;l<=3;l++){
                            if(i==j&&i==k||i==j&&i==l||i==k&&k==l||j==k&&j==l) continue;
                            ans=max(ans,a[1][i]+a[2][j]+a[3][k]+a[4][l]);
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }
        else{
            int ans=0;
            for(int i=1;i<=n;i++){
                d[i]=a[i][1];
            }
            sort(d+1,d+n+1,cmp);
            for(int i=1;i<=n/2;i++) ans+=d[i];
            cout<<ans<<endl;
        }
    }
    return 0;
}
