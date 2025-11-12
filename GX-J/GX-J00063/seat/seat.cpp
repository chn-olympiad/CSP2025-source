#include<bits/stdc++.h>
using namespace std;
int a[200];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==r)
        {
            int z=n*m-i+1;
            int x=ceil(1.0*z/n);
            int y=(z%n==0?n:(z%n));
            cout<<x<<" "<<(x%2==0?(n-y+1):y);
            break;
        }
    }
    return 0;
}
