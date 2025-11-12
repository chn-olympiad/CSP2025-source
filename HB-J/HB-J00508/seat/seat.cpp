#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,r,b,mc;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++)
        cin>>a[i];
    b=a[0];
    sort(a,a+n*m);
    for(int i=n*m;i>0;i--)
        if(a[i]==b)
        {
            b=n*m-i;
            break;
        }
    if(b%n==0)
        c=b/n;
    else
        c=b/n+1;
    if(c%2==0)
            r=n+1-(b-(b/n*n));
        else
            r=b-b/n*n;
    cout<<c<<' '<<r;
    return 0;
}
