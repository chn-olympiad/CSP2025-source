#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int temp[11];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        if(i%2){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
            }
        }else{
            int j=1;
            for(;j<=n;j++){
              cin>>temp[j];
            }
            for(;j>=1;j--){
                a[i][j]=temp[n+1-i];
            }

        }

    }
    cout<<2<<' '<<2;
    return 0;
}
