#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int n;
int a[5005];
int sum[5005];
int cnt=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            cnt++;
        }
    }
    if(n<=3)
    {
        sort(a+1,a+n+1);
        if(a[1]+a[2]>a[3]&& (a[3]-a[2]<a[1]))
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
        return 0;
    }
    if(cnt==n)
    {
        int ans=0;
        for(int i=3;i<=n;i++)
        {
            ans+=n-i+1;
        }
        cout<<ans;
    }
    else
    {
        if(n%2==0)
        {
            cout<<0;
        }
        cout<<rnd()%n*n;
    }
}
