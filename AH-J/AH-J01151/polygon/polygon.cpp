#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],m,s,c;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            s+=a[j];
            if(a[j]>m)m=a[j];
            if(s>m*2)
            {
                c++;
                s=0;
            }
        }
    }
    cout<<c;
    return 0;
}
