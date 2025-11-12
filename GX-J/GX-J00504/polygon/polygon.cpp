#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5004],z=0,i,j,ma=0,s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>ma)
        {
            ma=a[i];
        }
    }
    if(n==3)
    {
        s=a[0]+a[1]+a[2];
        if(s>ma*2)
        {
            z++;
            cout<<z;
        }
        else
        {
            cout<<0;
        }
    }return 0;
}
