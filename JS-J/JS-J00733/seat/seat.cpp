#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],b[50][50],tot,wz;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    wz=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int j=1;j<=m;j++){
       if(j%2==1){
            for(int i=1;i<=n;i++){
                if(wz==a[++tot]){
                    cout<<j<<' '<<i;
                    exit(0);
                }
                b[i][j]=a[tot];
            }
       }
       else {
            for(int i=n;i>=1;i--){
                if(wz==a[++tot]){
                    cout<<j<<' '<<i;
                    exit(0);
                }
                b[i][j]=a[tot];
            }
       }
    }
    return 0;
}
