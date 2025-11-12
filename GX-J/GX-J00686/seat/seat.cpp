#include<bits/stdc++.h>
using namespace std;
int a[105];
bool dx(int a,int b)
{
    return a>b;
}
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,b,c,r,i;
cin>>n>>m>>b;
a[1]=b;
for(i=2;i<=n*m;i++)
{
    cin>>a[i];
}
sort(a+1,a+1+n*m,dx);
i=1;
for(c=1;c<=m;c++)
{
    if(c%2==1)
    {
        for(r=1;r<=n;r++)
        {
            if(a[i]==b)
            {
                cout<<c<<' '<<r;
                return 0;
            }
            else i++;
        }
    }
    else
    {
        for(r=n;1<=r;r--)
        {
            if(a[i]==b)
            {
                cout<<c<<' '<<r;
                return 0;
            }
            else i++;
        }
    }
}
return 0;
}
