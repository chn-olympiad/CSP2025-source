#include <bits/stdc++.h>
using namespace std;
int n;
long long mod=998244353;
vector<int> a;
bool cmp(int a,int b)
{
    return a>=b;
}
long long dfs(long long x,long long p,long long c)
{
    c++;
    int cnt=c<3?c:3;
    if(p>=n||n-1-p<3-cnt)
    {
        return 0;
    }
    x-=a[p];
    long long ans=0;
    if(x<0&&cnt>=3)
    {
        return(1<<(n-p-1))%mod;
    }
    for(int i=p+1;i<n;i++)
    {
        ans=(ans+dfs(x,i,cnt))%mod;
    }
    return ans;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(),a.end(),cmp);
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        ans=(ans+dfs(2*a[i],i,0))%mod;
    }
    cout << ans%mod;
    return 0;
}
