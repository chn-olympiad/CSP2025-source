#include<bits/stdc++.h>
using namespace std;
int m,n,a[101],d,ans,x,y,pl;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    ans=a[1];
    for(int j=1;j<=n*m;j++){
        for(int i=1;i<=m*n;i++){
            if(a[i+1]>a[i]){
                d=a[i];
                a[i]=a[i+1];
                a[i+1]=d;

            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(ans==a[i]){
            pl=i;
        }
    }
    if(pl%n==0){
        x=pl/n;
        if(x%2==1){
            y=n;
        }else{
            y=1;
        }
    }else{
        x=pl/n+1;
        if(x%2==1){
            y=pl%n;
        }else{
            y=n-pl%n+1;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
