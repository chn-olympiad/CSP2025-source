#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],b[107];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>b[i];
    int x=b[1],y,sum=0;
    sort(b+1,b+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
        if(b[i]==x)
        {
            y=i;
            break;
        }
    for(int i=1;i<=n;i++)
    {
        if(i%2!=0)
            for(int j=1;j<=m;j++)
            {
                sum++;
                a[i][j]=sum;
                if(sum==y)
                {
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        else
            for(int j=m;j>=1;j--)
            {
                sum++;
                a[i][j]=sum;
                if(sum==y)
                {
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
    }
}
