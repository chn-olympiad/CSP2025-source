#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,q,c,d;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n>>m;
    b=m*n;
    for(int i=1;i<=b;i++)
    {
        cin>>a[i];
    }
    q=a[1];
    sort(a+1,a+1+b);
    for(int i=b;i>=1;i--)
    {
        if(a[i]==q)
        {
            q=b+1-i;
        }
    }
    c=ceil(q*1.0/n);
    d=q%n;
    cout<<c<<" ";
    if(c%2==0)
        cout<<n-d+1;
    else
        cout<<d;
    return 0;
}
