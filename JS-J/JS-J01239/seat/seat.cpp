#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int w,m,n,a[105],h,l,b[101]={0},c=1;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n*m;i++){
        b[a[i]]++;
    }
    for(int i=100;i>a[1];i--){
        c=b[i]+c;
    };
    if(c%n==0){
        h=c/n;
        if(h%2==0)
        {
            l=n;
        }else {
            l=1;
        }
    }else{
        h=c/m+1;
        if(h%2==0)
        {
            l=(n+1)-c%n;
        }else{
            l=c%m;
        }
    }
    cout<<h<<' '<<l;
    return 0;
}
