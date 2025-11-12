#include<bits/stdc++.h>
using namespace std;
int m,n;
int d(double k){
   if(k<ceil(k))return ceil(k)-1;
   return k;
}
struct op{
    int c,b,x;
}a[10001];
bool cmp(op x,op y){
    return x.c>y.c;
}
bool mn(op x,op y){
    return x.x<y.x;
}
int main(){
    freopen("seat.in","w",stdin);
    freopen("seat.out","r",stdout);
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++){
        cin>>a[i].c;
        a[i].x=i;
    }
    sort(a+1,a+k+1,cmp);
    for(int i=1;i<=k;i++)a[i].b=i;
    sort(a+1,a+k+1,mn);
    int l;
    if(a[1].b%n==0)l=a[1].b/n;
    else l=d(1.0*a[1].b/n)+1;
    cout<<l<<' ';
    if(l%2==1){
        if(a[1].b%n==0)cout<<n;
        else cout<<a[1].b%n;
    }
    else {
        if(a[1].b%n==0)cout<<1;
        else cout<<n-a[1].b%n;
    }
    return 0;
}
