#include<bits/stdc++.h>
using namespace std;
int n,m,z,ans,c,d;
int a[150];
bool cmptt(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    z=n*m;
    cin>>ans;
    a[1]=ans;
    for (int i=2;i<=z;i++)
        cin>>a[i];
    sort(a+1,a+z+1,cmptt);
    for (int i=1;i<=z;i++)
    {
        if (a[i]==ans)
        {
            c=i/n+1;
            if (i%n==0)
                c=c-1;
            d=i%n;
            if (d==0)
                d=n;
            if (c%2==0)
                d=n-d+1;
            cout<<c<<" "<<d<<endl;
            return 0;
        }
    }
    return 0;
}
