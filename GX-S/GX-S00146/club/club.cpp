#include<bits/stdc++.h>
using namespace std;
int t,n;
int f[2][2010][2010];
int a[100100][4];
int ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(f,0,sizeof(f));
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        for(int i=1;i<=n;i++){
            for(int b=0;b<=n/2;b++){
                for(int c=0;c<=n/2;c++){
                    f[i%2][b][c]=f[(i-1)%2][b][c];
                }
            }
            for(int j=min(i,n/2);j>=0;j--){
                for(int k=min(i-j,n/2);k>=0;k--){
                    if(i-j-k>n/2){
                        break;
                    }
                    if(j>0){
                        f[i%2][j][k]=max(f[i%2][j][k],f[(i-1)%2][j-1][k]+a[i][1]);
                    }
                    if(k>0){
                        f[i%2][j][k]=max(f[i%2][j][k],f[(i-1)%2][j][k-1]+a[i][2]);
                    }
                    if((i-j-k<=n/2)&&(i-j-k>0)){
                        f[i%2][j][k]=max(f[i%2][j][k],f[(i-1)%2][j][k]+a[i][3]);
                    }
                    ans=max(f[i%2][j][k],ans);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
