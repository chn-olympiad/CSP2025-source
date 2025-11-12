#include <bits/stdc++.h>
using namespace std;
int n,m,arr[101],c,r,xr,rb;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[(i-1)*m+j];
        }
    }
    int xr=arr[1];
    sort(arr+1,arr+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(arr[i]==xr){
            rb=i;
            break;
            }
    }
    if(rb%n!=0){
        c=rb/n+1;
    }else{
        c=rb/n;
    }
    if(c%2==1){
        if(rb%n==0){
            r=n;
        }else{
        r=rb%n;
        }
    }else{
        if(rb%n==0){
            r=1;
        }else{
    r=n-rb%n+1;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
