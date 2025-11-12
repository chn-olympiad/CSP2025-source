#include "bits/stdc++.h"
using namespace std;
int a[105];
int ans[105];
int s,n,m,k;
int c,r;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    s=n*m;
    for(int i=1;i<=s;i++)
    {
        cin>>ans[i];
        a[ans[i]]=1;

    }
    for(int i=100;i>=ans[1];i--)
    {
        if(a[i])
        {
            k++;
        }
    }
    int mo=k%n;
    if(k%n==0)
    {
        c=k/n;
    }
    else{
        c=k/n+1;
    }
    if(c%2==0)
    {
        r=n+1-mo;
    }
    else{
        r=mo;
    }
    cout<<c<<" "<<r;
    return 0;
}
