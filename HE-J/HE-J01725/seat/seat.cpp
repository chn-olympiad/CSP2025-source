#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[15][15];
bool cpp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.in","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int ans=a[1];
    sort(a+1,a+n*m+1,cpp);
    int t=1;
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                b[i][j]=a[t];
                t++;
            }
        }
        else{
            for(int i=n;i>=1;i--){
                b[i][j]=a[t];
                t++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==ans){
                cout<<j<<" "<<i;
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
