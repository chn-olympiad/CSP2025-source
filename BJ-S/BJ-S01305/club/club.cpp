#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,t;
int a[maxn][5];
int ans;
bool flag=1;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
   cin>>t;
   while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                if(a[i][2]||a[i][3]) flag=0;
            }
        }
       if(n==2){
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    ans=max(ans,a[1][i]+a[2][j]);
                }
            }
       }
      if(n==4){
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    for(int k=1;k<=3;k++){
                        for(int z=1;z<=3;z++){
                            if(i==j&&j==k||i==k&&k==z||i==z&&j==z||j==k&&k==z) continue;
                                ans=max(ans,a[1][i]+a[2][j]+a[3][k]+a[4][z]);
                        }
                    }
                }
            }
       }
       if(flag){
            sort(a+1,a+n+1);
            for(int i=1;i<=n/2;i++){
                ans+=a[i][1];
            }
       }
       cout<<ans<<endl;
   }
return 0;
}
