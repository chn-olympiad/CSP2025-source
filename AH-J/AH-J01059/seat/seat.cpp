#include<bits/stdc++.h>
using namespace std;
int a[200];
int z[20][20];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int x=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j%2==1){
               z[i][j]=a[(j-1)*n+i];
            }
            if(j%2==0){
                if(i==1){
                   z[i][j]=a[j*n];
                }
                else{
                    z[i][j]=a[j*n-i+1];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(z[i][j]==x){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
