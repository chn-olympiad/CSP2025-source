#include<bits/stdc++.h>
using namespace std;
long long a[5005],zmax=0,h=0;
int main()
{
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n;
cin>>n;
if(n<3)
    {
        cout<<0;
return 0;
}
for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>zmax)zmax=a[i];
        h+=a[i];

    }
    if(h>zmax*2)cout<<1;

return 0;
}



