#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,c;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int u=n*m;
    for(int i=0;i<u;i++)
    {
        cin>>a[i];
    }
    b=a[0];
    sort(a,a+u,cmp);
    for(int i=0;i<u;i++)
    {
        if(a[i]==b)
        {
            c=i+1;
            break;
        }
    }
    int x1=ceil(c*1.0/n);
    int x2=c%n;
    if(x2==0)
    {
        x2=n;
    }
    if(x1%2==0)
    {
        cout<<x1<<" "<<n+1-x2;
    }
    else
    {
        cout<<x1<<" "<<x2;
    }
    return 0;
}
