#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[110],x[110],y[110],t=1;
bool cmp(int l,int r)
{
    return l>r;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    int r=a[1];
    for(int i=2;i<=n*m;i++)
        cin>>a[i];
    sort(a+1,a+1+n*m,cmp);
    int ll=1,rr=0;
    for(int i=1;i<=n*m;i++)
    {
        if(ll%2==1)
        {
            if(rr==n)
                ll++;
            else
                rr++;
        }
        else
        {
            if(rr==1)
                ll++;
            else
                rr--;
        }
        x[i]=ll,y[i]=rr;
    }
    for(int i=1;i<=n*m;i++)
        if(a[i]==r)
        {
            cout<<x[i]<<" "<<y[i];
            break;
        }

    return 0;
}
