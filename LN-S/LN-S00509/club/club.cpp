#include<bits/stdc++.h>
using namespace std;
const int mxN=1e5+1;
int T,a[mxN][4],f[mxN][4],vis[mxN];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(int t=1;t<=T;t++){
        int n,m;
        scanf("%d",&n);
        m=n/2;
        int mx=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        }
        if(n==2){
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    if(i==j) continue;
                    mx=max(mx,a[1][i]+a[i][j]);
                }
            }
            cout<<mx<<endl;
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=max(a[i][1],max(a[i][2],a[i][3]));
        }
        cout<<ans<<endl;
    }
    return 0;
}
