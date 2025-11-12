#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    t=n*m;
    for(int i=1;i<=t;i++)  cin>>a[i];
    int ans=a[1];
    sort(a+1,a+t+1);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(a[t-i*n+n-j+1]==ans){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                if(a[t-i*n+j]==ans){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
