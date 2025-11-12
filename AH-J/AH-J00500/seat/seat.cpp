#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110],b[110],xr,s[11][11];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
    cin>>a[i];
}
xr=a[1];
sort(a,a+m*n+1);
for(int i=n*m;i>=1;i--){
    b[n*m-i+1]=a[i];
}
int k=1;
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++,k++){
        s[j][i]=b[k];
    }
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(s[i][j]==xr){
            if(j%2==0){
                i=n-i+1;
            }
            cout<<j<<" "<<i;
        return 0;
        }
    }
}
return 0;
}
