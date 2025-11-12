#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],R,c,r;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i==1)R=a[i];
        a[i]=-a[i];
    }
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++)
    {
        if(-a[i]==R)
        {

            if(i/m*m!=i)c=i/m+1;
            else c=i/m;
            if(c%2==0)
            {
                if(i%n==0) r=1;
                else r=n-i%n+1;
            }
            else
            {
                if(i%n==0) r=n;
                else r=i%n;
            }
            cout<<c<<' '<<r;
            return 0;
        }
    }
    return 0;
}
