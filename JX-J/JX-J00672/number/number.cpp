#include <bits/stdc++.h>
using namespace std;
int mian()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[1000000+5];
    for(int i=1;i<=1e6;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=1e6;i++)
    {
        for(int j=1;j<=1e6;j++)
        {
            if(a[j]<a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(int i=1;i<=1e6;i++)
    {
		cout<<a[i];
    }
    return 0;
}
