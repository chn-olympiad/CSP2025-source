#include <bits/stdc++.h>
using namespace std;
int n,m,a[225],f[15][15],zc;
bool cmp(int x,int y){
    return x>y;
}
void pz(int x,int j){
    if(j%2==1){
        for(int i=1;i<=n;i++){
            f[i][j]=a[(j-1)*n+i];
        }
        if(x==n&&j==m){
            return;
        }
        pz(n,j+1);
    }else{
        for(int i=n;i>=1;i--){
            f[i][j]=a[n*(j-1)+(n+1-i)];
        }
        if(x==n&&j==m){
            return;
        }
        pz(1,j+1);
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    zc=a[1];
    sort(a+1,a+n*m+1,cmp);
    pz(1,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(f[i][j]==zc){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
