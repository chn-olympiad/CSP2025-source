#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
    }
    int t=a[1];
    sort(a+1,a+k+1,cmp);
    for(int i=1;i<=k;i++)
    {
        if(a[i]==t)
        {
            t=i;
            break;
        }
    }
    int x=1,y=0;
    for(int i=1;i<=t;i++)
    {
        if(x&1)
        {
            y++;
        }
        else
        {
            y--;
        }
        if(y>n)
        {
            y=n;
            x++;
        }
        if(y<1)
        {
            y=1;
            x++;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
