#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[110],f=1,a1,c,r;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++) cin>>a[i];
    a1=a[1];
    sort(a+1,a+n*m+1,cmp);
    while(a[f]!=a1) f++;
    r=f%n;
    if(r!=0){
        c=f/n+1;
        if(c%2==0) r=n+1-r;
    }
    else{
        c=f/n;
        if(c%2==0) r=1;
        else r=n;
    }
    cout<<c<<' '<<r;
    return 0;
}
