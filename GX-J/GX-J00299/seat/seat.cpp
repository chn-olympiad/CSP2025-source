#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,b[11][11],f=0,y=1;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        x=a[1];
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m;i++)
    {
        if(f==0)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[y]==x)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                else
                    y++;
            }
            f=1;
        }
        else if(f==1)
        {
            for(int j=n;j>=1;j--)
            {
                if(a[y]==x)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                else
                    y++;
            }
            f=0;
        }
    }
    return 0;
}
