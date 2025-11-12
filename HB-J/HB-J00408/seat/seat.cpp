#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[20][20],b[400],ans,N,M,B=1;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    ans=b[1];
    sort(b+1,b+n*m+1,cmp);
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            for(int j=1;j<=m;j++){
                a[j][i]=b[B];
                B++;
            }
        }else{
            for(int j=m;j>=1;j--){
                a[j][i]=b[B];
                B++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==ans){
                cout<<j<<" "<<i;
            }
        }
    }
    return 0;
}
