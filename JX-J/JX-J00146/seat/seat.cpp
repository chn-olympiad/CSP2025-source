#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int c[105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int z=n*m;
    for(int i=1;i<=z;i++){
        cin>>c[i];
    }
    int ans=c[1];
    sort(c+1,c+z+1,cmp);
    int k=1;
    int p=0,r=0;
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                a[i][j]=c[k];
                k++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                a[i][j]=c[k];
                k++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==ans){
                p=i;
                r=j;
            }
        }

    }
    cout<<p<<" "<<r;
    return 0;
}
