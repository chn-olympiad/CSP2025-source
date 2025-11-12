#include <bits/stdc++.h>
using namespace std;
int n,m,a1,x,y;
int a[500];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    a1=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==a1){
            a1=i;
            break;
        }
    }
    if(a1%n==0){
        y=a1/n;
        if(y%2==0){
            x=1;
        }
        else{
            x=n;
        }
    }
    else{
        y=a1/n+1;
        if(y%2==0){
            x=n-a1%n+1;
        }
        else{
            x=a1%n;
        }
    }
    cout<<y<<' '<<x;
    return 0;
}
