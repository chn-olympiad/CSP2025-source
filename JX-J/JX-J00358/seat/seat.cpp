#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],b[105],c,d,e,x,y,o;
    cin>>m>>n;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    for(int i=100;i>=0;i--){
        for(int j=1;j<=n*m;j++){
            if(a[j]==i){
                b[100-i+1]=i;
            }
        }
    }
    for(int j=1;j<=n*m;j++){
        if(a[1]==b[j]) o=j;
    }
    c=a[1];
    d=o/n;
    e=o%n;
    if(d%2==0){
        x=d;
        y=m-e;
    }
    if(d%2==1){
        x=d;
        y=e;
    }
    cout<<x<<y;
    return 0;
}
