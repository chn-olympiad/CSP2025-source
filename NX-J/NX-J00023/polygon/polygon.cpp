#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[1010]={0},c=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=3;i<=n;i++)
    {
        for(int j=0;j<=n-i+1;j++)
        {
            if(a[j]*i+i-1/2>a[j+2])
            {
                c++;
            }
        }
    }
    cout<<c;

    return 0;
}
