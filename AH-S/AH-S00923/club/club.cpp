#include<bits/stdc++.h>
using namespace std;
const int N=1e5+114;
int n,ans,a[N][5],b[N],f[214][114][114];
void init()
{
    memset(f,0,sizeof(f));
    ans=0;
}
int main()
{

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
        if(n<=200){
            f[1][1][0]=a[1][0],f[1][0][1]=a[1][1],f[1][0][0]=a[1][2];
            for(int i=2;i<=n;i++)
             for(int j=0;j<=i;j++)
              for(int k=0;j+k<=i;k++){
                f[i][j][k]=f[i-1][j][k]+a[i][2];
                if(j) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][0]);
                if(k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][1]);
              }
            for(int i=0;i<=(n>>1);i++)
             for(int j=0;j<=(n>>1);j++)
              if(i+j>=(n>>1)) ans=max(ans,f[n][i][j]);
            cout<<ans<<'\n';

        }
        else{
            int sum=0;
            for(int i=1;i<=n;i++) sum+=a[i][0],b[i]=a[i][1]-a[i][0];
            sort(b+1,b+1+n);
            for(int i=n;i>(n>>1);i--) ans+=b[i];
            cout<<ans+sum<<'\n';
        }
        init();
   }
    return 0;
}
