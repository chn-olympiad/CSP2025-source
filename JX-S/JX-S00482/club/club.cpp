#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7,M=203;
int t,n,a[N][3],b[N],f[M][M][M];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        int tmps=0;
        for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2],tmps+=a[i][1]+a[i][2];
        if(!tmps){
            long long res=0;
            for(int i=1;i<=n;i++)b[i]=a[i][0];
            sort(b+1,b+n+1);
            for(int i=n;i>n/2;i--)res+=b[i];
            cout<<res<<"\n";
            continue;
        }
        int res=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n/2;j++){
                for(int k=0;k<=n/2&&j+k<=i;k++){
                    f[i][j][k]=0;
                    if(j)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][0]);
                    if(k)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][1]);
                    if(j+k<i)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][2]);
                    if(i==n&&j+k>=n/2)res=max(res,f[i][j][k]);
                }
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}