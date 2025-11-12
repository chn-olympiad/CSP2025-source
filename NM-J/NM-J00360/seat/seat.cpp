#include<bits/stdc++.h>
using namespace std;
int a[110],b[110];
int cj,zw;
int n,m,sum;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    cj=a[1];
    for(int i=cj+1;i<=100;i++){
        if(b[i]!=0){
            sum++;
        }
    }
    zw=sum+1;
    int l;
    if(zw%n==0){
        l=zw/n;
    }else{
        l=zw/n+1;
    }
    int h;
    if(l%2==0){
        h=n-(zw%n)+1;
    }else{
        if(zw%n==0){
            h=n;
        }else{
            h=zw%n;
        }
    }
    cout<<l<<" "<<h;
    return 0;
}
