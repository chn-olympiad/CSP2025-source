#include<bits/stdc++.h>
using namespace std;
int n,m,arr[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>arr[i];
    }
    int me=arr[1];
    sort(arr+1,arr+1+m*n);
    int cnt=m*n;
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                if(arr[cnt]==me){
                    cout<<j<<' '<<i;
                    return 0;
                }
                cnt--;
            }
        }
        else{
             for(int i=n;i>=1;i--){
                if(arr[cnt]==me){
                    cout<<j<<' '<<i;
                    return 0;
                }
                cnt--;
            }
        }
    }
    return 0;
}
