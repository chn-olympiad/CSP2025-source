#include<bits/stdc++.h>
using namespace std;
int n,m,fy,y,a[106],s,h,l;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    s=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--)
    {
        if(a[i]==s)
        {
            fy=i;
            y=n*m-i+1;
            break;
        }

    }
    if(y%2==0)
        h=y/2;
    else if(y%2==1)
        h=y/2+1;
    if(h%2==0)
        l=y-n*(n*m-(y))+1;
    if(h%2==1)
    {
        l=y-n*(n*m-y);
    }
    if(l<0)
        cout<<h<<" "<<-l;
    if(l>0)
        cout<<h<<" "<<l;
    return 0;
}
