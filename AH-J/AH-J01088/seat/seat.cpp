#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,y,t;
    cin>>n>>m;
    int a[n*m],b[n*m];
    for(int i=0;i<m*n;i++)
        cin>>b[i],a[i]=b[i];
    sort(b,b+n*m);
    for(int i=n*m;i>0;--i)
        if(a[0]=b[i]) t=i+1;
    if(t%n==0) x=t/m;
    if(t%n!=0) x=t/m+1;
    if(x%2==0) y=x*n+1-t;
    if(x%2==1) y=t-t*(x-1);
    cout<<x<<" "<<y;
    return 0;
}
