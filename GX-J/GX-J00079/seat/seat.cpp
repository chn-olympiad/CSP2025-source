#include<bits/stdc++.h>
using namespace std;
int a[109];
int b[50][50];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,ans;
    bool flag=1;
    cin>>m>>n;
    int x=n*m;
    for(int i=1;i<=x;i++){
        cin>>a[i];
        ans=a[1];
    }
    sort(a,a+x+1);
    for(int i=1;i<=n;i++){
        if(flag){
            for(int j=1;j<=m;j++){
                b[i][j]=a[x];
                if(b[i][j]==ans){
                    cout<<i<<" "<<j;
                    return 0;
                }
                x--;
                flag=0;
            }
        }else{
            for(int j=m;j>=1;j--){
                b[i][j]=a[x];
                if(b[i][j]==ans){
                    cout<<i<<" "<<j;
                    return 0;
                }
                x--;
                flag=1;
            }
        }
    }
    return 0;
}
