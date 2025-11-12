#include <bits/stdc++.h>
using namespace std;
int n,a[5000],i,j;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
              swap(a[i],a[j]);
        }
    }
    if(a[0]+a[1]<=a[n-1])
      cout<<"0";
    else
      cout<<"1";
    return 0;
}
