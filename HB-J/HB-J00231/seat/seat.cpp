//100pts
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int score=a[1];
    sort(a+1,a+n*m+1);
    int place;
    for(int i=1;i<=n*m;i++){
        if(a[i]==score) {place=n*m-i+1; break;}
    }
    int c=(place+n-1)/n;
    int r;
    if(c%2==1){
        r=place%n;
        if(r==0) r=n;
    }
    else{
        r=n-place%n+1;
        if(r==n+1) r=1;
    }
    cout<<c<<' '<<r;
    return 0;
}