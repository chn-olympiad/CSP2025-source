#include<bits/stdc++.h>
const int N=101,M=1e5+5;
int f[N][N][N],a[M],b[M],c[M];
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
        if(n>200&&c[200]==0){
            for(int i=1;i<=n;i++) ans+=b[i],a[i]=a[i]-b[i];
            sort(a+1,a+n+1);
            for(int i=n/2+1;i<=n;i++) ans+=a[i];
            cout<<ans<<endl;
            continue;
        }
        if(n>200){
            for(int i=1;i<=n;i++) ans+=max(a[i],max(b[i],c[i]));
            cout<<ans<<endl;
        }
        memset(f,0,sizeof(f));
        for(int i=0;i<=n/2;i++){
            for(int j=0;j<=n/2;j++){
                for(int k=0;k<=n/2;k++){
                    if(i>=1) f[i][j][k]=max(f[i-1][j][k]+a[i+j+k],f[i][j][k]);
                    if(j>=1) f[i][j][k]=max(f[i][j-1][k]+b[i+j+k],f[i][j][k]);
                    if(k>=1) f[i][j][k]=max(f[i][j][k-1]+c[i+j+k],f[i][j][k]);
                    if(i+j+k==n){
                        ans=max(ans,f[i][j][k]);
                        break;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
