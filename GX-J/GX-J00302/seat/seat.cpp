#include<bits/stdc++.h>
using namespace std;
int p[102],r,rb;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin >>p[i];
    }
    r=p[1];
    sort(p+1,p+1+n);
    for(int i=1;i<=n*m;i++)
    {
        if(p[i]=r)
        {
            rb=n*m-i+1;
            break;
        }
    }
    int len=0;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            for(int j=m;j>=1;j--)
            {
                len++;
                if(len==rb)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }

            }
        }
        else
        {
            for(int j=1;j<=m;j++)
            {
                len++;
                if(len==rb)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }

    }
    return 0;
}
