#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],b[101],num=0,c,d;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n*m;i++){
        if(b[1]=a[i]){
            num=i;
        }
    }
    if(num%n==0){
        c=num/n;
    }
    else{
        c=num/n+1;
    }
    if(c%2==1){
        d=num%n;
    }
    else{
        d=n-num%n;
    }
    cout<<c<<" "<<d;
    return 0;
}
