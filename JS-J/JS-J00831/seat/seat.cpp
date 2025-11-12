#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[105],A,I;
bool cmp(int x,int y){
    return x>y;
}
int x,y;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=(n*m);i++){
        cin>>a[i];
    }
    A=a[1];
    sort(a+1,a+1+(n*m),cmp);
    for(int i=1;i<=(n*m);i++){
        if(a[i]==A){
            I=i;
            break;
        }
    }
    if(I%n) x=I/n+1;
    else x=I/n;
    if(x%2){
        y=I%n;
        if(y==0) y=n;
    }
    else{
        y=I%n;
        if(y==0) y=n;
        y=n-(y-1);
    }
    cout<<x<<' '<<y;
    return 0;
}
