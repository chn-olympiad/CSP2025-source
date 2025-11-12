#include <bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],idx,maxn=-1,tot;
long long ans;
void dfs(int i)
{
    if(i>n)
    {
        if(idx<3) return;
        if(tot>maxn*2) ans++;
        ans%=998244353;
        idx=0;
        maxn=-1;
        tot=0;
        return;
    }
    for(int j=1;j<=n-i-1;j++)
    {
        for(int k1=i;k1<=i+j-1;k1++)
        {
            b[++idx]=a[k1];
            maxn=max(maxn,b[idx]);
            tot+=b[idx];
            dfs(i+2);
        }
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==3)
    {
        for(int i=1;i<=n;i++)
        {
            maxn=max(maxn,a[i]);
            tot+=a[i];
        }
        if(tot>maxn*2) ans++;
    }
//    for(int i=1;i<=n;i++)
//    {
//        dfs(i);
//    }
    cout<<ans%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
