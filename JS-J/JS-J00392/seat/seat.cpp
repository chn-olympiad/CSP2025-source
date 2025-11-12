#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],p[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int k=a[1];
    sort(a+1,a+n*m+1);
    int l=m*n;
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=n;j>=1;j--){
                p[i][j]=a[l];
                l--;
            }
        }
        else{
            for(int j=1;j<=n;j++){
                p[i][j]=a[l];
                l--;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(p[i][j]==k){
                cout<<i<<" "<<j;
            }
        }
    }
    return 0;
}
