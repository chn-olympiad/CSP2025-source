#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],aa[105],f;
    cin>>n>>m;
    int b[n+1][m+1];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    f=a[1];
    sort(a+1,a+n*m+1);
    int tt=1;
    for(int i=n*m;i>=1;i--){
        aa[tt]=a[i];
        tt++;
    }
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                b[i][j]=aa[(i-1)*n+j];
                if(b[i][j]==f){
                    cout<<i<<" "<<j;
                    fclose(stdin);
                    fclose(stdout);
                    return 0;
                }
            }
        }
        if(i%2==0){
            for(int j=n;j>=1;j--){
                b[i][j]=aa[(i-1)*n+n+1-j];
                if(b[i][j]==f){
                    cout<<i<<" "<<j;
                    fclose(stdin);
                    fclose(stdout);
                    return 0;
                }
            }
        }
    }
}
