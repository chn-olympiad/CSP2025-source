#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,a1,num,c,r;
bool cmp(int x,int y)
{
    return x>y;
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
    a1=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==a1)
        {
            num=i;
            break;
        }
    }
    if(num%n!=0)
        c=num/n+1;
    else
        c=num/n;
    if(c%2==1)
    {
        r=num%n;
        if(r==0)
        {
            r==n;
        }
    }
    else
        r=n-num%n+1;
    cout<<c<<" "<<r;
    return 0;
}
