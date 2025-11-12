#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005];
long long ans;
int s[5005];
int ss;
void dfs(int k,int cnt)
{
    if(k>n)
    {
        if(cnt>(s[ss]*2))ans++;
        return;
    }
    for(int i=0;i<=1;i++)
    {
        b[k]=i;
        cnt+=b[k]*a[k];
        if(i)ss++,s[ss]=a[k];
        dfs(k+1,cnt);
        if(i)ss--;
        cnt-=b[k]*a[k];
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
    sort(a+1,a+n+1);
    dfs(1,0);
    cout<<ans%998244353;
    return 0;
}
