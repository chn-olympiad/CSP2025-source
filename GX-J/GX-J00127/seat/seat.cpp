#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[15],b[15],c[105],x,y,num=0;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
        a[i]=i;
    for(int i = 1;i<=m;i++)
        b[i]=i;
    for(int i = 1;i<=n*m;i++)
    {
        cin>>c[i];
        if(i==1)
            x=c[i];
    }
    sort(c+1,c+n*m+1,cmp);
    for(int i = 1;i<=n*m;i++)
    {
        if(c[i]==x)
        {
            y=i;
            break;
        }
    }
    for(int i = 1;i<=n;i++)
    {
        if(i%2==1)
        {
            for(int j = 1;j<=m;j++)
            {
                num++;
                if(num==y)
                {
                    cout<<i<<" "<<j;
                    break;
                }
            }
        }
        else
        {
            for(int j = m;j>=1;j--)
            {
                num++;
                if(num==y)
                {
                    cout<<i<<" "<<j;
                    break;
                }
            }
        }
    }
    return 0;
}
