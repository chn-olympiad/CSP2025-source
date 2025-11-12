#include <bits/stdc++.h>
using namespace std;
struct qwe
{
    int num;
    int s;
}a[110];
bool cmp(qwe q,qwe w)
{
    return q.s>w.s;
}
int n,m;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i].s;
        a[i].num=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int x;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i].num==1)
        {
            x=i;
            break;
        }
    }
    int i=x/n;
    if(i*n!=x)
    {
        i++;
    }
    int j=x%n;
    if(i%2==1)
    {
        if(j==0)
        {
            cout<<i<<' '<<n;
        }
        else
        {
            cout<<i<<' '<<j;
        }
    }
    else
    {
        if(j==0)
        {
            cout<<i<<' '<<1;
        }
        else
        {
            cout<<i<<' '<<n-j+1;
        }
    }
    return 0;
}
