#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],f[15][15],y,cnt;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int pos=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    for(int j=1;j<=m;j++){
        if(j%2==0){
            for(int i=n;i>=1;i--){
                f[i][j]=a[++cnt];
            }
        }else{
            for(int i=1;i<=n;i++){
                f[i][j]=a[++cnt];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(f[i][j]==pos){
                cout<<j<<" "<<i;
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
