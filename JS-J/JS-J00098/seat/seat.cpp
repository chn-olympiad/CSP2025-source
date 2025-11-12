#include<bits/stdc++.h>
using namespace std;
int a[10001],k,n,m,t;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    k=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==k) k=i;
    }
    t=(k-1)/n+1;
    if(t%2==1) k-=(t-1)*n;
    else k=n-(k-(t-1)*n)+1;
    cout<<t<<" "<<k;
    return 0;
}
