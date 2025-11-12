#include <bits/stdc++.h>
using namespace std;
int n,m;
struct R{
    int s,t;
};
R a[100005];
bool comp(R x,R y)
{
    return x.s>y.s;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    a[0].t=1;
    for (int i=0;i<n*m;i++)
    {
        cin>>a[i].s;
    }
    sort(a,a+n*m,comp);
    int ans=0;
    for (int i=0;i<n*m;i++)
    {
        if (a[i].t)
        {
            ans=i;
            break;
        }
    }
    int l=ans/n;
    ans%=n;
    if (l%2==1)
    {
        ans=n-ans;
    }
    else
    {
        ans++;
    }
    cout<<l+1<<" "<<ans;
    return 0;
}
