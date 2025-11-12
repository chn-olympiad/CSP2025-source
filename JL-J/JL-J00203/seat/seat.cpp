#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int m;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k=0;
    int b=1;
    int a[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(i==1&&j==1){
                k=a[i][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]>k) b++;
        }
    }
    int x=0;
    int y=0;
    if(b%n==0){
        x=b/n;
        if(x%2==1){
            y=n;
        }
        else{
            y=1;
        }
    }

    if(b%n==1){
        x=b/n+1;
        if(x%2==1){
            y=b%n;
        }
        else{
            y=n+1-b%n;
        }
    }
    cout<<x<<" "<<y;
}
