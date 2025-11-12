#include<bits/stdc++.h>
using namespace std;
int m,n,ls1,ls2=1,x,y;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<n*m;j++){
            if(a[j]<a[j+1]){
                ls1=a[j];
                a[j]=a[j+1];
                a[j+1]=ls1;
                if(j==ls2)ls2=j+1;
                else if(j+1==ls2)ls2=j;
            }
        }
    }
    if(ls2%n==0)y=ls2/n;
    else y=ls2/n+1;
    if(ls2%n==0){
    if(y%2==0)x=1;
    else x=n;}
    else{
    if(y%2==0)x=n-ls2%n+1;
    else x=ls2%n;}
    cout<<y<<' '<<x;
    return 0;
}
