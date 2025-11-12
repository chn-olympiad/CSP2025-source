#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[5003];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int w=0,r=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int y=w;
            w+=a[i];
            if(i>=3)
            {
               if(y>a[i]*2)r++;
            }
         }
    }
    cout<<r;
    return 0;
}
