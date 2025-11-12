#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int h,l,n,m,t,r,a[120];
bool cmd(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    t=n*m;
    for(int i=1;i<=t;i++)
        cin>>a[i];
    a[0]=a[1];
    sort(a+1,a+t+1,cmd);
    for(int i=1;i<=t;i++)
        if(a[i]==a[0])
        {
            r=i;
            break;
        }
    l=r/n,h=r%n;
    if(!h)l--,h=n;
    if(l%2)h=n-h+1;
    cout<<l+1<<' '<<h;
    return 0;
}
