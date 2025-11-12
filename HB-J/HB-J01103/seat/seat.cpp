#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15],x,f;
int g[1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>g[i];
    int b=g[1];
    sort(g+1,g+1+n*m);
    for(int i=m*n,j=1;i>=1;i--,j++){
        if(g[i]==b){
            x=j;
            break;
        }
    }
    int h,l=x/n;
    if(x%n){
        l++;
        if(l%2)h=x%n;
        else h=n-x%n+1;
    }
    else {
        if(l%2)h=n;
        else h=1;
    }
    cout<<l<<' '<<h;
    return 0;
}
