#include<bits/stdc++.h>
using namespace std;
int n,m,lx,ly,t,a[114],g;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a[1];
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>a[1])t++;
    }
    lx=t/n+1;
    g=t%n+1;
    if(lx%2==1)ly=g;
    else ly=m-g+1;
    cout<<lx<<' '<<ly;
    return 0;
}
