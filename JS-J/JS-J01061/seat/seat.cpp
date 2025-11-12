#include <bits/stdc++.h>
using namespace std;
int n;int m;int a[200];int r;int num;int ansn;int ansm;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<=n*m-1;i++)cin>>a[i];
    r=a[0];
    sort(a,a+n*m);
    for(int i=0;i<=n*m-1;i++)if(a[i]==r)num=n*m-i;
    if(num%n==0)ansm=num/n;
    else ansm=num/n+1;
    if(num%(2*n)<=n)if(num%n==0)ansn=n;else ansn=num%n;
    else if(num%n==0)ansn=1;else ansn=n-(num%n)+1;
    cout<<ansm<<' '<<ansn;
    return 0;

    }
