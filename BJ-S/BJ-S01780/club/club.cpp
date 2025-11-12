#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t;
int a[N][5];
int f[N][5];
int w[5][N][5];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                a[i][j]=0;
                f[i][j]=0;
                for(int l=1;l<=3;l++){
                    w[l][i][j]=0;
                }
            }
        }
        int cur=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        for(int i=1;i<=3;i++){
            f[1][i]=a[1][i];
        }
        w[1][1][1]=1;
        w[2][1][2]=1;
        w[3][1][3]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=3;j++){
                int flag=0,maxx=0;
                for(int l=1;l<=3;l++){
                    if(w[j][i-1][l]<cur){
                        if(f[i-1][l]>=maxx){
                           maxx=f[i-1][l];
                           flag=l;
                        }
                    }
                    else{
                        w[j][i][l]=w[j][i-1][l];
                    }
                }
                f[i][j]=maxx+a[i][j];
                for(int m=1;m<=3;m++){
                    if(m!=flag){
                        w[j][i][m]=w[j][i-1][m];
                    }
                    else w[j][i][m]=w[j][i-1][m]+1;
                }

            }
        }

        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cout<<f[i][j]<<' ';
            }
            cout<<endl;
        }
*/
        cout<<max(f[n][1],max(f[n][2],f[n][3]))<<endl;
    }
    return 0;
}
