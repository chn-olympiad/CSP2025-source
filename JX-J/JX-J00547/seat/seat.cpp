#include<bits/stdc++.h>
using namespace std;
int n,m,a[2200],c,r,s;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int t=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            s=n*m-i+1;
            break;
        }
    }
    int c=(s-1)/n+1;
    if(s%n!=0){
        if(c%2==0)r=n-s%n+1;
        if(c%2==1)r=s%n;
    }
    if(s%n==0){
        if(c%2==0)r=1;
        if(c%2==1)r=n;
    }
    cout<<c<<" "<<r;
    return 0;
}
