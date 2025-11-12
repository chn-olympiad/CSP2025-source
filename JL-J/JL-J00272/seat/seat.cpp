#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1010],h,b,t,c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    h=n*m;
    for(int i=0;i<h;i++){
        cin>>a[i];
    }
    b=a[0];
    sort(a,a+h);
    for(int i=0;i<h;i++){
        if(a[i]==b){
            t=h-i;
        }
    }
    c=int(ceil(1.0*t/n));
    if(c%2==1){
        if(t%n>0)   r=t%n;
        if(t%n==0)  r=n;
    }
    if(c%2==0)  r=n-(t%n)+1;
    cout<<c<<" "<<r;
    return 0;
}
