#include<bits/stdc++.h>
using namespace std;
int a[120];
bool cmd(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a1;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    a1=a[1];
    sort(a+1,a+1+n*m,cmd);
    int seat;
    for(int i=1;i<=n*m;i++){
        if(a[i]==a1){
            seat=i;
        }
    }
    int c,r;
    c=ceil(double(seat)/n);
    r=seat%n;
    if(r==0)r=n;
    if(c%2==0){
        r=n-r+1;
    }
    if(r==0)r=n;
    cout<<c<<' '<<r;
    return 0;
}
