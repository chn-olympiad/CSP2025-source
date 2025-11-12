#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],zw[15][15],cnt;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int x=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                cnt++;
                zw[i][j]=a[cnt];
            }
        }else{
            for(int j=m;j>=1;j--){
                cnt++;
                zw[i][j]=a[cnt];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(zw[i][j]==x){
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    return 0;
}
