#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1005;
LL n,m,a[N],R,tot,s[N][N];
bool isord;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n*m;i++) cin>>a[i];
    R=a[1];
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    for(LL j=1;j<=m;j++){
        isord=!isord;
        if(isord) for(LL i=1;i<=n;i++) s[i][j]=a[++tot];
        else for(LL i=n;i>=1;i--) s[i][j]=a[++tot];
    }
    for(LL i=1;i<=n;i++){
            for(LL j=1;j<=m;j++)
                if(s[i][j]==R)
                    cout<<j<<" "<<i;
    }
    return 0;
}
