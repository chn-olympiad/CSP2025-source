#include<bits/stdc++.h>
using namespace std;
int a[105],aa[15][15];
int cmp(int a,int b){
    return a>b;
}
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m;
    int cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int f=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                aa[i][j]=a[++cnt];
            }
        }
        else{
            for(int i=n;i>=1;i--){
                aa[i][j]=a[++cnt];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(aa[i][j]==f){
                cout<<j<<' '<<i;
            }
        }
    }
    return 0;
}
