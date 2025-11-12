#include<bits/stdc++.h>
#define E 10010
using namespace std;
int n,m,c,r,f,tep;
int a[E],mp[E][E];
bool cmp(int x1,int x2)
{
    if(x1>=x2)
        return x1>x2;
    else
        return x2<x1;
}
int pf(int m)
{
    for(int i=0;i<m*n;i++)
    {
        if(f==a[i])
        {
            cout<<1<<" "<<i+1;
            return 0;
        }
    }
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
        cin>>a[i];
    f=a[0];
    sort(a,a+m*n,cmp);
    if(n==1)
        pf(m);
    for(int i=0;i<m*n;i++)
        if(f==a[i])
            tep=i+1;
    int chu=tep/n,sha=tep%n;
    if(sha==0)
    {
        chu--;
        sha+=n;
    }
    cout<<chu<<sha<<endl;
    if((chu+1)%2==0)
    {
        for(int i=n;i>0;i--)
        {
            mp[i][chu+1]=chu*n+n-i+1;
            if(mp[i][chu+1]==tep)
            {
                c=chu+1;
                r=i;
            }
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            mp[i][chu+1]=chu*n+i;
            if(mp[i][chu+1]==tep)
            {
                c=chu+1;
                r=i;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
