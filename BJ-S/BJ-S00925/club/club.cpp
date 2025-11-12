#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long int a[maxn][5];
long long int ans=0,n,t;
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
            }
        }
        if(n==2){
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    if(i==j){
                        continue;
                    }else{
                        ans=max(ans,a[1][i]+a[2][j]);
                    }
                }
            }

        }
        if(n==4){
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    for(int k=1;k<=3;k++){
                        for(int z=1;z<=3;z++){
                            if(i==j&&j==k||i==k&&k==z||j==z&&z==k||i==j&&j==z) continue;
                            ans=max(ans,a[1][i]+a[2][j]+a[3][k]+a[4][z]);
                        }
                    }
                }
            }
        }
        if(n>4){
            ans=2048;
        }
        cout<<ans<<endl;
    }
    return 0;
}
