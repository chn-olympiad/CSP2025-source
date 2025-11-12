#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=305;
int t,n,a[maxn],b[maxn],c[maxn],ans;
int f[maxn][maxn][maxn],g[maxn][maxn];
bool f2,f3;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
            f2=f3=0;
        memset(f,0,sizeof(f));
        ans=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
            if(b[i]!=0) f2=1;
            if(c[i]!=0) f3=1;
        }
        if(f2==0&&f3==0){
            sort(a+1,a+1+n);
            for(int i=n;i>n/2;i--){
                ans+=a[i];
            }
            cout<<ans;
            continue;
        }
        else if(f3==0){
                memset(g,0,sizeof(g));
            for(int p=1;p<=n;p++){
                for(int i=n/2;i>=0;i--){
                    for(int j=n/2;j>=0;j--){
                        if(i) g[i][j]=max(g[i][j],g[i-1][j]+a[p]);
                        if(j) g[i][j]=max(g[i][j],g[i][j-1]+b[p]);
                        ans=max(ans,g[i][j]);
                    }
                }
            }
            cout<<ans<<endl;
            continue;
        }
        for(int p=1;p<=n;p++){
            for(int i=n/2;i>=0;i--){
                for(int j=n/2;j>=0;j--){
                    for(int k=n/2;k>=0;k--){
                        if(i) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[p]);
                        if(j) f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+b[p]);
                        if(k) f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+c[p]);
                        ans=max(ans,f[i][j][k]);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
/*

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=505;
int t,n,a[maxn],b[maxn],c[maxn],ans;
int f[maxn][maxn][maxn];
signed main(){
    freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        memset(f,0,sizeof(f));
        ans=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
            //f[1][]
        }
        for(int p=1;p<=n;p++){
            for(int i=n/2;i>=0;i--){
                for(int j=n/2;j>=0;j--){
                    for(int k=n/2;k>=0;k--){
                        if(i) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[p]);
                        if(j) f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+b[p]);
                        if(k) f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+c[p]);
                        ans=max(ans,f[i][j][k]);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
*/
