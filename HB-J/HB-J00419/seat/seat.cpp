#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],xr,ii,jj;
int cnt=1;
int b[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1) xr=a[i];
    }
    sort(a+1,a+1+n*m,greater<int>());
    for(int i=1;i<=m;i++){
        if(i%2==1) for(int j=1;j<=n;j++) b[j][i]=a[cnt++];
        else for(int j=n;j>=1;j--) b[j][i]=a[cnt++];
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        if(b[i][j]==xr){
            ii=i,jj=j;
            break;
        }
    cout<<jj<<" "<<ii;
    return 0;
}
