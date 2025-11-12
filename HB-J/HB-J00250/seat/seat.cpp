#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],s,p,x,y;
bool ck(int i,int j){
    return i>j;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    s=a[1];
    sort(a+1,a+n*m+1,ck);
    for(int i=1;i<=n*m;i++){
        if(a[i]==s){
            p=i;
            break;
        }
    }
    if(p%n==0){
        y=p/n;
        if(y%2==0) x=1;
        else x=n;
    }
    else{
        y=p/n+1;
        if(y%2==0) x=n-p%n+1;
        else x=p%n;
    }
    cout<<y<<" "<<x;
    return 0;
}
