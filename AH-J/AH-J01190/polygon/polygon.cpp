#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n+1],b[n+1],ma=0,num=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    memset(b,1,sizeof(b));
    sort(a+1,a+n+1);
    if(n==3)
    {
        if(a[3]<a[1]+a[2])
        {
            num++;
        }
    }
    cout<<num;
    return 0;
}
