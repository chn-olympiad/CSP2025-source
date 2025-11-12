#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n,k;
int a[5010];
int book[5010];
bool check()
{
    long long sum=0;
    int mx=0;
    for(int i=1;i<=k;i++)
    {
        sum+=book[i];
        mx=max(mx,book[i]);
    }
    return sum>2*mx;
}
void dfs(int id,int num)
{
    if(num==k)
    {
        if(check()==1)
            ans=(ans+1)%998244353;
        return;
    }
    for(int i=id+1;i<=n;i++)
    {
        book[num+1]=a[i];
        dfs(i,num+1);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        k=i;
        dfs(0,0);
    }
    cout<<ans<<endl;
    return 0;
}
