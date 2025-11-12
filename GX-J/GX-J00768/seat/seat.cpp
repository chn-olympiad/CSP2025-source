#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b,c,d,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    c=n*m;
    for(int i=1;i<=c;i++){
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+1+c);
    for(int i=1;i<=c;i++){
        if(a[i]==b){
            d=c-i+1;
            break;
        }
    }
    if(d%n==0)y=d/n;
    else y=d/n+1;
    if(y%2==1){
        x=d-n*(y-1);
    }
    else{
        x=d-n*(y-1);
        x=n-x+1;
    }
    cout<<y<<" "<<x;
    return 0;
}
