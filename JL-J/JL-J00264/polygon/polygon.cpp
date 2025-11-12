#include <bits/stdc++.h>
using namespace std;
long long ans=0;
    int a[5010];
        int n;
void f(int x,long long sum)
{
    //cout<<sum<<endl;
    //cout<<sum<<endl;
    for(int i=x+1;i<=n;i++)
    {
        if(sum>a[i]){ans++;}
        sum+=a[i];
        f(i,sum);
        sum-=a[i];
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    f(0,0);
    cout<<ans%998244353;
    return 0;
}
