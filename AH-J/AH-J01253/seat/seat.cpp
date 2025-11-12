#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,b[15][15],f[9],x=1,y=1;
struct node{
    long long o;
    bool fl;
}a[110];
bool cmp(node q,node w)
{
    return q.o>w.o;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n*m;i++)
    {
        if(i==1)
        {
            cin>>a[i].o;
            a[i].fl=1;
        }
        else
        {
            cin>>a[i].o;
        }
    }
    sort(a+1,a+1+n*m,cmp);
    if(a[i].fl==1)
    {
        cout<<x<<' '<<y;
        return 0;
    }
    f[1]=1;
    for(i=2;i<=n*m;i++)
    {
        if(f[1]==1)
        {
            if(y+1>n)
            {
                x++;
                f[1]=0;
                f[2]=1;
            }
            else
            {
                y++;
            }
        }
        else
        {
            if(y-1<1)
            {
                x++;
                f[1]=1;
                f[2]=0;
            }
            else
            {
                y--;
            }
        }
        if(a[i].fl==1)
        {
            cout<<x<<' '<<y;
            return 0;
        }
    }
    return 0;
}
