#include<bits/stdc++.h>
using namespace std;
int a[5001],n,ans=0;
int df(int dep,int last,int sum)
{
    if(dep>=3&&sum>a[last]*2)
        ans++;
    for(int i=last+1;i<=n;i++)
        df(dep+1,i,sum+a[i]);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    bool b=true;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)b=false;
    }
    sort(a+1,a+n+1);
    if(b)
    {
        long long aa=pow(2,n-1);
        cout<<aa;
        return 0;
    }
    if(n==3)
    {
        if(a[3]<a[1]+a[2])cout<<1;
        else cout<<0;
        return 0;
    }
    df(0,0,0);
    cout<<ans%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
