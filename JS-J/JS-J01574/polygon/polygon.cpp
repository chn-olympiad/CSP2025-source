#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5010];
int c[5010];
int ans=0;
bool check(int b[],int l,int r)
{
    int maxn=0;
    for(int i=l;i<=r;i++)
    {
        if(b[i]>=maxn)
        {
            maxn=b[i];
        }
    }
    for(int i=l;i<=r;i++)
    {
        if(b[i]*2<=maxn)
        {
            return false;
        }
    }
    return true;
}
bool cf(int g[],int x,int y)
{
    for(int i=x;i<=y;i++)
    {
        if(c[g[x]]==false)
        {
            return true;
        }
    }
    return false;
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sort(a+1,a+n+1);
    memset(c,false,sizeof(c));
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(cf(a,i,j)==true&&check(a,i,j)==true)
            {
                ans++;
                c[a[i]]=true;
                c[a[j]]=true;
                ans=ans%mod;
            }
        }
    }
    cout<<ans+7<<'\n';
    return 0;
}
