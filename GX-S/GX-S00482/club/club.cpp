#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int t,n,a[5][N],x[5][N],vis[5][N],f,ma,mb,mc,ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    cin>>n;
    while(t--){
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[1][i]>>a[2][i]>>a[3][i];
            f=max(a[1][i],a[2][i]);
            ans+=max(f,a[3][i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f=max(a[1][i],a[2][j]);
                if(1){
                    for(int k=1;k<=3;k++){
                        f=a[k][i];
                        a[k][i]=a[k][j];
                        a[k][j]=f;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
