#include <bits/stdc++.h>
using namespace std;
int a[4];
int main()
{freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n,sum=0;
cin>>n;
for(int i=1;i<=n;i++)
{

    cin>>a[i];
}
for(int i=0;i<n;i++)
{
    for(int j=1;j<=n-i;j++)
    {

        if(a[j]>a[j+1])
        {

            swap(a[j],a[j+1]);
        }
    }
}
if(a[1]+a[2]>a[3])
{

    sum++;
}
cout<<sum<<endl;
return 0;
}
