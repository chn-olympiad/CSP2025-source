#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int h;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    h=a[1];
    int j=n*m;
    while(j--)
    {
        for(int i=2;i<=n*m;i++)
        {
            if(a[i-1]<a[i]) swap(a[i],a[i-1]);
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                int s=(i-1)*n+j;
                if(a[s]==h)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                int s=(i-1)*n+n+1-j;
                if(a[s]==h)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
