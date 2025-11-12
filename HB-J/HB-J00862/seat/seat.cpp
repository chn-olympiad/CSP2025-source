#include<bits/stdc++.h>
using namespace std;
struct node
{
    int s;
    int id;
}a[1010];
bool cmp(node a,node b)
{
    return a.s>b.s;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n*m;i++) cin>>a[i].s,a[i].id=i;
    sort(a+1,a+1+n*m,cmp);
    int x=1,y=1,c=0;
    for (int i=1;i<=n*m;i++)
    {
        if (a[i].id==1)
        {
            cout<<x<<" "<<y<<endl;
            return 0;
        }
        if (c==0)
        {
            y++;
            if (y==n+1)
            {
                y=n;
                x++;
                c=1;
            }
        }
        else
        {
            y--;
            if (y==0)
            {
                y=1;
                x++;
                c=0;
            }
        }
    }
    return 0;
}
