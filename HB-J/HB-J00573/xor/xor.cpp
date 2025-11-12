#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int k,n,i,a[500001]={},j,f=0,p=0,x=1,q,t1=0,t2=0,o=0;
    cin>>n>>k;
    cin>>a[1];
    for(i-2;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++)if(a[i]==1)p++;
    if(p==n){
        for(i=1;i<n;i++)x=x*i;
        cout<<x;
    }
    return 0;
}
