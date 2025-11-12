#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int u,int v)
{
    return u>v;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
        cin>>a[i];
    int x=a[0];
    sort(a,a+n*m,cmp);
    int t;
    for(int i=0;i<n*m;i++)
        if(a[i]==x)
            t=i;
    int c=t/n+1,r;
    if(c%2==1)
        r=t%n+1;
    else
        r=n-t%n;
    cout<<c<<' '<<r;
    return 0;
}
