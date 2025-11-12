#include <bits/stdc++.h>
using namespace std;
int n,m,a[10060];
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen ( "seat.in","r",stdin);
    freopen ( "seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int b=a[1];
    sort(a+1,a+n*m+1,cmp);
    int i=1,x=0,y=0,cz=0;
    while(a[i]!=b){
        i++;
    }
    y=(i+n-1)/n;
    cz=i-(y-1)*n;
    if(y%2==0){
        x=n-cz+1;
    }
    else{
        x=cz;
    }
    cout<<y<<" "<<x;
    return 0;
}
