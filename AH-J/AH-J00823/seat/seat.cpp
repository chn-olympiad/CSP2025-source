#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,b[205],a[205][205],k,i,l,r,x;
bool cmp(ll w,ll e)
{
    return w>e;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
            cin>>b[++k];
    x=b[1];
    sort(b+1,b+k+1,cmp);
    i=0;
    l=1;
    r=1;
    while(i!=k)
    {
        a[l][r]=b[++i];
        if(l<2)
        {
            while(l<n&&i!=k)
            {
                l++;
                a[l][r]=b[++i];
            }
        }
        else
        {
            while(l>1&&i!=k)
            {
                l--;
                a[l][r]=b[++i];

            }
        }
        r++;
    }
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
            if(a[i][j]==x)
            {
                cout<<j<<" "<<i;
                return 0;
            }
    return 0;
}
