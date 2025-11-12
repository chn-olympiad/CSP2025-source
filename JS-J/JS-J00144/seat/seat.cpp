#include <bits/stdc++.h>
using namespace std;
struct stu
{
    int xh,cj;
}a[1000005];
bool cmp(stu x,stu y)
{
    return x.cj>y.cj;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i].cj;
        a[i].xh=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int x=1,y=1,f=0;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i].xh==1)
        {
            cout<<x<<' '<<y;
            return 0;
        }
        if(y==n&&f==1)
        {
            x++;
            f*=-1;
            continue;
        }
        if(y==1)
        {
            if(f==0)
            {
                f=1;
            }
            else
            {
                x++;
                f*=-1;
                continue;
            }
        }
        if(f==1)
        {
            y++;
        }
        else
        {
            y--;
        }
    }
    return 0;
}
