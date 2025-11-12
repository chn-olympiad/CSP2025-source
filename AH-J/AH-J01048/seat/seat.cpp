#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=15;
LL a[N*N],b[N][N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    LL n,m;
    cin>>n>>m;
    for(LL i=1;i<=n*m;i++){
        cin>>a[i];
    }
    LL d=a[1],tot=0;
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    for(LL i=1;i<=m;i++){
        if(i%2==1){
            for(LL j=1;j<=n;j++){
                b[i][j]=a[++tot];
            }
        }
        else{
            for(LL j=n;j>=1;j--){
                b[i][j]=a[++tot];
            }
        }
    }
    for(LL i=1;i<=m;i++){
        for(LL j=1;j<=n;j++){
            if(b[i][j]==d){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
