#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],b[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1; i<=n*m; i++){
        cin>>a[i];
    }
    int xr=a[1];
    sort(a+1,a+1+n*m);
    reverse(a+1,a+1+n*m);
    int x=0;
    for(int j=1; j<=m; j++){
        if(j%2==0){
            for(int i=n; i>=1; i--){
                x++;
                b[i][j]=x;
            }
        }
        else{
            for(int i=1; i<=n; i++){
                x++;
                b[i][j]=x;
            }
        }
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++){
    //         cout<<b[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[b[i][j]]==xr){
                cout<<j<<' '<<i<<endl;
                // cout<<a[b[i][j]]<<' ';
                break;
            }
        }   
    }
    return 0;
}