#include <bits/stdc++.h>
using namespace std;
struct node
{
    int id,s;
} a[105];
int n,m;
bool cmp(node x,node y)
{
    return x.s>y.s;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        a[i].id=i;
        cin>>a[i].s;
    }
    sort(a+1,a+n*m+1,cmp);
    for (int i=1;i<=n*m;i++)
        if (a[i].id==1)
        {
            int c,r;
            if (i%n!=0)
                c=i/n+1;
            else
                c=i/n;
            if (c%2==0)
                r=n-i%n+1;
            else
                r=(i-1)%n+1;
            cout<<c<<" "<<r;
            break;
        }
    return 0;
}