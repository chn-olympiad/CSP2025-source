#include<bits/stdc++.h>
using namespace std;
int n,m,x[110],y[110],a[110];
bool cmp(int s,int c)
{
    return s>c;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int p=a[1],t=0,l=n*m;
    sort(a+1,a+1+l,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==p)
        {
            t=i;
            break;
        }
    }
    x[0]=1;
    for(int i=1;i<=n*m;i++)
    {
        if(i%n!=0)x[i]=i/n+1;
        else x[i]=i/n;
        if(x[i]%2==0)
        {
            if(x[i-1]==x[i])y[i]=y[i-1]-1;
            else y[i]=n;
        }
        else
        {
            if(x[i-1]==x[i])y[i]=y[i-1]+1;
            else y[i]=1;
        }
        if(i==t)
        {
            cout<<x[i]<<" "<<y[i];
            break;
        }
    }
    return 0;
}