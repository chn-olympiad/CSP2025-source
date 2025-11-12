#include<bits/stdc++.h>
#define rg register
#define ll long long
using namespace std;
ll n,m,r,k=0;
ll a[11000];
inline ll rd(){
    char c;
    ll x=0,sig=1;
    for(c=getchar();c<'0'||c>'9';c=getchar())
        if(c=='-')sig=-1;
    for(;c>='0'&&c<='9';c=getchar())
        x=x*10+c-48;
    return x*sig;
}
void wok(){
    n=rd();m=rd();
    for(rg ll i=1;i<=n*m;i++)
        a[i]=rd();
    r=a[1];
    for(rg ll i=1;i<=n*m;i++)
        for(rg ll j=i+1;j<=n*m;j++)
            if(a[i]<a[j])swap(a[i],a[j]);
    while(a[++k]!=r);
    ll x,y;
    if(k%n==0){
        y=k/n;
        if(y%2==1)x=n;
        else x=1;
    }
    else {
        y=k/n+1;
        if(y%2==1)x=k%n;
        else x=n-k%n+1;
    }
    cout<<y<<" "<<x;
    return;
}
void fre(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    return;
}
int main(){
    fre();
    wok();
    return 0;
}
