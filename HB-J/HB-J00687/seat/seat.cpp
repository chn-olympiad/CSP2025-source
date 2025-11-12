#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("sent.out","w",stdout);
    int n,m,p,q,l,h;
    cin>>n>>m;
    int a[n*m+1],i;
    for(i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    p=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(i=1;i<=m*n;i++)
    {
        if(a[i]==p)
            q=i;
    }
    l=(q+n-1)/n;
    if(l%2==1)
    {
        h=q%n;
        if(h==0)
          h=n;
    }
    else
    {
        h=n-q%n+1;
    }
    cout<<l<<" "<<h;
    return 0;
}
