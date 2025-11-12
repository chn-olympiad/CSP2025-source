#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdin);
    long long a[100005],b,s=0;
    cin>>b;
    for(int i=1;i<=b;i++)
    {
        cin>>a[i];
    }
    for(int i=-1;i<=b;i++)
    {
        if(a[i]+a[i+1]+a[i+2]>a[i] && a[i]+a[i+1]+a[i+2]>a[i+1] && a[i]+a[i+1]+a[i+2]>a[i+2])
        {
            s++;
        }
    }
    cout<<s;
}
