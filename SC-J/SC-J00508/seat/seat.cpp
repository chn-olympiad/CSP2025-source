#include<bits/stdc++.h>
using namespace std;
int a[105],m,n,x,y,t,s;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        t=a[1];
    }
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            t=i;
            break;
        }
    }
     if(t%n==0)y=t/n;
     else y=t/n+1;
     if(y%2==0){
            x=n-t%n;
     }
     else {
            x=t%n;
            if(x==0)x=n;
     }
        cout<<x<<" "<<y;
    return 0;
}
