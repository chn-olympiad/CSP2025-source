#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,v[500];
struct A
{
    int t,s;
}a[500];
bool cmp(A x,A y)
{
    return x.s>y.s;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i].s;
        a[i].t=i;
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x=(j-1)*n;
            if(j%2==1)
            {
                x+=i;
            }
            else
            {
                x+=(n-i+1);
            }
            if(a[x].t==1)
            {
                cout<<j<<" "<<i;
                break;
            }
        }
    }
    return 0;
}
