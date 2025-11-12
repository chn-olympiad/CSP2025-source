#include<bits/stdc++.h>
using namespace std;
int n,s,l;
long long b[5050],a[5050];
long long ans=0;
void xzm(int x)
{
    if (s<=l)
    {
        b[s]=a[x];
        s++;
        for (int i=x+1;i<=n;i++)
            xzm(i);
        }
    else
    {
        long long ans1=0,ans2=-1;
        for (int i=1;i<=s;i++)
        {
            ans1=(ans1+b[i])%998244353;
            ans2=max(ans2,b[i]);

        }
        s--;
        ans2=ans2*2;
        if (ans1>ans2)
            ans=(ans+1)%998244353;
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=3;i<=n;i++)
    {
        l=i;
        for (int j=1;j-1+i<=n;j++)
        {
            s=1;
            xzm(j);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
