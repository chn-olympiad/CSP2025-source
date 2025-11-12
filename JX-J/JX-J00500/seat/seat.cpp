#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long p[105][105]={},n,m,a[100000],l;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    l=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==l)
        {
            l=n*m-i;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=m;j++)
            {
                if(l==0)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                l--;
            }
        }
        if(i%2==0)
        {
            for(int j=m;j>=1;j--)
            {
                if(l==0)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                l--;
            }
        }
    }
    return 0;
}
