#include <bits/stdc++.h>
using namespace std;
int sz[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>sz[i];
    }
    sort(sz,sz+n);
    int maxx=sz[n-1];
    int s=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=j;k<n;k++)
            {
                if(i+j+k>maxx)
                    s++;
            }
        }
    }
    cout<<s%998244353;
    return 0;
}
