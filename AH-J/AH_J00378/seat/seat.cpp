#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int k=a[1];
    sort(a+1,a+n*m+1,cmp);
    int pos;
    for(int i=1;i<=n*m;i++)
        if(a[i]==k)
        {
            pos=i;
            break;
        }
    int c,r;
    if(pos%n==0)
    {
        c=pos/n;
        if(c%2==0)
            r=1;
        else
            r=n;
    }
    else
    {
        c=pos/n+1;
        if(c%2==0)
            r=n-pos%n+1;
        else
            r=pos%n;
    }
    cout<<c<<" "<<r;
    return 0;
}
