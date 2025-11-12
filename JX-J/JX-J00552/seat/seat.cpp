#include <bits/stdc++.h>
using namespace std;
int n,m,t,cnt;
struct px
{
    int x,id;
}a[105];
bool cmp(px x,px y)
{
    return x.x>y.x;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i].x;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i].id==1)t=i;
    }
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                cnt++;
                if(cnt==t)
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
                cnt++;
                if(cnt==t)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
