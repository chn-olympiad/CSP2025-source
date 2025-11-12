#include <iostream>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,xr,max,xr_seater=0;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            max=a[0][0];
            if(max<a[i][j]){
                max=a[i][j];
                xr_seater++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=n;j>0;j--){
                if(ans==xr_seater){
                    break;
                }
                ans++;
            }
        }
        else{
            for(int j=1;j<=n;j++){
                if(ans==xr_seater){
                    break;
                }
                ans++;
            }
        }
        if(ans==xr_seater){
            break;
        }
    }
    cout<<i<<" "<<j;
    return 0;

}
