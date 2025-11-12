#include<bits/stdc++.h>
using namespace std;
int a[10005],d,b,f,s,n,m,c,t;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    b=n*m;
    for(int i=1;i<=b;i++){
        cin>>a[i];
    }
    f=a[1];
    for(int i=1;i<b;i++){
        if(a[i]<=a[i+1])swap(a[i],a[i+1]);
    }
    for(int i=1;i<=b;i++){
        if(a[i]==f)s=i;
    }
    t=s%n;
    d=s/n+1;
    if(t==0)d=s/n;
    if(d%2==0 && t!=0)c=n-t+1;
    if(d%2==0 && t==0)c=1;
    if(d%2==1 && t!=0)c=t;
    if(d%2==1 && t==0)c=n;
    cout<<d<<" "<<c;
    return 0;
}
