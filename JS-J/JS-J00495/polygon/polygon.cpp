#include <bits/stdc++.h>

using namespace std;
long long n,a[5005],ans;
bool px(long long x,long long y)
{
    return x>y;
}
void dfs(long long now,long long cho,long long all,long long lag,long long s)
{
    if(all==cho)
    {
        if(lag*2<s)
            ans++;
        else
            return ;
    }
    for(long long i=now+1;i<=n;i++)
        dfs(i,cho+1,all,lag,s+a[i]);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >>n;
    for(long long i=1;i<=n;i++)
        cin >>a[i];
    sort(a+1,a+n+1,px);
    for(long long i=3;i<=n;i++)
    {
        for(long long j=1;j<=n;j++)
            dfs(j,1,i,a[j],a[j]);
    }
    cout <<ans;
    return 0;
}
