#include<bits/stdc++.h>
using namespace std;
long long a[500005],f[500005],k,n,l,r;;
long long slove_123(long long x)
{
    long long ans=0,now=a[x];
    for(int i =x-1;i>=1;i--)
    {
        if(now==k)
        {
            ans++;
            now = a[i];
        }
        else
        {
            now^=a[i];
        }
    }
    if(now == k)
    {
        ans++;
    }
    return ans;
}
long long max_123(long long a,long long b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(f,-1,sizeof(f));
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i =1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i<=n;i++)
    {
        f[i]=max_123(slove_123(i),f[i-1]);
    }
    cout << f[n];
    return 0;
}
