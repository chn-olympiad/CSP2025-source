#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=0,m=0,b=0,c=0,d=0,p=0,k=0,v=0,a[101];
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    b=m*n;
    cin>>a[1];
    c=a[1];
    for(int i=2;i<=b;i++){
        cin>>a[i];

    }
    sort(a+1,a+b+1);
    for(int i=1;i<=b;i++){
        if(a[b-i+1]==c){
          d=i;

        }

    }
    p=d-1;
    k=p%n;
    p=p/n;
    p+=1;
    if(p%2==0){
        cout<<p<<' '<<n-k;
    }else{
        cout<<p<<' '<<k+1;
    }

    return 0;
}
