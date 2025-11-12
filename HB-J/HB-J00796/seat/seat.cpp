#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,e,q=1,w=0;
    cin>>n>>m;
    int a;
    for(int i=1;i<=n*m-1;i++)
    {
        if(i==1)
        {
            cin>>a;
            e=a;
        }
        cin>>a;
        if(e<a)
        {
            q++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
          for(int j=1;j<=m;j++)
            {
                w++;
                if(w==q)
                {
                    cout<<i<<' '<<j;
                }
            }
        }
        else
        {
            for(int j=m;j>=1;j--)
            {
                w++;
                if(w==q)
                {
                    cout<<i<<' '<<j;
                }
            }
        }
    }
    return 0;
}
