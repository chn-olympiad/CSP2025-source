#include <bits/stdc++.h>
#define  ll long long
using namespace std;
int F(int a)
{
    if(a==1) return 1;
    return a*F(a-1);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    ll sum=0;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==3)
    {
        if((a[1]+a[2]<=a[3])||(a[1]+a[3]<=a[2])||(a[2]+a[3]<=a[1]))
        {
            cout<<0;
            return 0;
        }
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(n-i==0)
        {
            sum+=1;
        }
        sum=sum+(F(n)/(F(i)*F(n-i)));
    }
    cout<<sum%998%244%353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
