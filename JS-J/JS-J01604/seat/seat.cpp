#include <bits/stdc++.h>
using namespace std;

int a[100],m,n,b=1;


int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0 ;i<m*n;i++)
    {
        cin>>a[i];
    }
    for(int i=1 ;i<m*n;i++)
    {
        if(a[i]>a[0])
            b++;
    }
    int out2=b/n;
    if(b%n!=0)out2++;
    int out1=(b-1)%n+1;
    if(out2%2==0)out1=n-out1+1;
    else if(out1==0)out1=n;

    cout<<out2<<' '<<out1;
}
