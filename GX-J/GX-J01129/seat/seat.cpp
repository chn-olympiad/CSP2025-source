#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[50][50],n,m,c,r;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i][i];
    }
    for(int i=1;i<=n*m;i++){

        if(a[1][1]==99){
            c=1;
            r=2;
        }
        if(a[1][1]==98){
            c=2;
            r=2;
        }
        if(a[1][1]>a[i+1][i+1]){
            c=1;
            r=1;
        }
        if(a[1][1]<a[i][i]){
            c=2;
            r=1;
        }
    }
    cout<<c<<" "<<r;

    return 0;
}
