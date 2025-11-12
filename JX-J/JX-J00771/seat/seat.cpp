#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005][1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int u=a[1];
    sort(a+1,a+n*m+1);
    int y=n*m;
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=n;j>=1;j--){
                b[i][j]=a[y];
                if(a[y]==u){
                    cout<<i<<" "<<j;
                    return 0;
                }
                y--;
            }
        }else{
            for(int j=1;j<=n;j++){
                b[i][j]=a[y];
                if(a[y]==u){
                    cout<<i<<" "<<j;
                    return 0;
                }
                y--;
            }
        }
    }
    return 0;
}
