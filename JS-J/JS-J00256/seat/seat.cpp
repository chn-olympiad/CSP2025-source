#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,y=1;
int a[1000],b[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int ans=a[1];
    sort(a+1,a+n*m+1);
    x=1;
    y=1;
    for(int i=n*m;i>=1;i--){
        b[x][y]=a[i];
        if(a[i]==ans){
            cout<<y<<" "<<x;
            return 0;
        }
        if(y==n){y++;x=1;}
        else x++;
    }
    return 0;
}
