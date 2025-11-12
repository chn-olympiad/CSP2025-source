#include<bits/stdc++.h>
using namespace std;
int n,m,a[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    int ans,xb;
    ans=a[0];
    sort(a,a+n*m);
    for (int i=n*m;i>=0;i--)
    {
        if(a[i]==ans)
        {
            xb=n*m-i;
            break;
        }
    }
    int rn=xb/n,rm,rr=xb%n;
    if(rr!=0)
    {
        rn+=1;
    }
    if(rr==0)
    {
        rr=n;
    }
    if(rn%2==0)
    {
        rm=n-rr+1;
    }
    else
    {
        rm=rr;
    }
    cout<<rn<<" "<<rm;
    return 0;
}
