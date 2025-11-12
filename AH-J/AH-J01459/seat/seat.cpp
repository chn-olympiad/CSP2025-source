#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,a[101],z,v,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int c=n*m;;
    for(int i=1;i<=c;i++){
        cin>>a[i];
        if(i==1)z=a[i];
    }
    sort(a+1,a+c+1);
    int h=c;
    for(int i=c;i>=1;i--){
        if(a[i]==z){v=h-i+1;}
        c--;
    }
    if(v%n==0){
        if(v/n%2==0){x=1;y=v/n;}
        else if(v/n%2==1){x=n;y=v/n;}
    }
    else if(v%n!=0){
        if((v/n+1)%2==0){x=(n+1)-(v%n);y=v/n+1;}
        else if((v/n+1)%2==1){x=v%n;y=v/n+1;}
    }
    cout<<y<<" "<<x;
    return 0;
}
