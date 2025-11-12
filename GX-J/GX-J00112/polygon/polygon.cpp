#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
long long n,a[3003],r=0;
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
}
if(n<3)
{
    cout<<0;
    return 0;
}
if(n==3)
{
    cout<<1;
    return 0;
}
for(int i=1;i<=n;i++)
{
    int q=0,w=0;
    for(int j=i+1;j<=n;j++)
    {
        for(int l=i;l<=j;l++)
        {
            q+=a[l];
            if(a[l]>w)
            {
                w=a[l];
            }
        }
        if(q>w*2)
        {
            r++;
        }
    }
}
cout<<r%998244353;
return 0;
}
