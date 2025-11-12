#include<bits/stdc++.h>
#define int long long
using namespace std;
const int NM=1e2+5;
int a[NM];
bool cmp(int a,int b)
{
    return a>b;
}
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n*m; ++i)
    {
        cin>>a[i];
    }
    int x=a[1],s;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1; i<=n*m; ++i)
    {
        if(a[i]==x)
        {
            s=i;
            break;
        }
    }
    int c=s/n,r;
    if(s%n)
    {
        ++c;
    }
    if(c%2)
    {
        if(s%n)
        {
            r=s%n;
        }
        else
        {
            r=n;
        }
    }
    else
    {
        if(s%n)
        {
            r=n-s%n+1;
        }
        else
        {
            r=1;
        }
    }
    cout<<c<<' '<<r;
    return 0;
}
