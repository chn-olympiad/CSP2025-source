#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[11][11]={},b[101]={};
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    int ans=b[1];
    int z=n*m;
    sort(b,b+z,cmp);
    int c=0;
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            for(int j=1;j<=m;j++){
                a[i][j]=b[c++];
            }
        }
        else if(i%2==0){
            for(int k=m;k>=1;k--){
                a[i][k]=b[c++];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==ans){
                cout<<i<<" "<<j;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
