#include <bits/stdc++.h>
using namespace std;
int n;
int a[6000];
const long long modn=998244353;
long long dfs(int cnt,int sizen,int maxn,int count)
{
    //cout << cnt << " " << sizen << " " << maxn << " " << count << endl;
    if(cnt>=n)
    {
        if(sizen>maxn*2&&count>=3)
        {
            return 1;
        }
        return 0;
    }
    long long ans=0;
    ans+=dfs(cnt+1,sizen,maxn,count);
    ans%=modn;
    long long nsize=sizen+a[cnt];
    long long nmax=maxn;
    if(a[cnt]>maxn) nmax=a[cnt];
    ans+=dfs(cnt+1,nsize,nmax,count+1);
    ans%=modn;
    //cout << ans << endl;
    return ans;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout << dfs(0,0,0,0) << endl;

    return 0;
}