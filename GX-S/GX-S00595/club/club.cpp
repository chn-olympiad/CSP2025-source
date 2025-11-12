#include <bits/stdc++.h>
using namespace std;
int t,n,ans,sp,a[5][100010],f[5][100010],b[100010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        sp=n>>1;
        for(int j=1;j<=n;j++){
            cin>>a[1][j]>>a[2][j]>>a[3][j];
        }
    for(int k=1;k<=n;k++){
        b[k]=a[1][k];
    }
    sort(b+1,b+n+1);
    for(int k=n;k>sp;k--)
        ans+=b[k];
    cout<<ans<<endl;
    }
    return 0;
}
