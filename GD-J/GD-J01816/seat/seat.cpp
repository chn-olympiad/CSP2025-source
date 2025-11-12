#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1100],x,h,l,s;
bool cmp(long long px,long long py)
{
    return px>py;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(long long i=1;i<=m;i++)
    {
        for(long long j=1;j<=n;j++)
        {
            s++;
            if(a[s]==x)
            {
                cout<<i<<" ";
                if(i%2==1)
                {
                    cout<<j;
                }else
                {
                    cout<<n-j+1;
                }
                return 0;
            }
        }
    }
    return 0;
}
