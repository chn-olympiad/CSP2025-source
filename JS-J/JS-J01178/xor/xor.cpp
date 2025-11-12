#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,p,a[500010],s[500010];
map<int,vector<int> >mp;
struct qu
{
    int l,r;
}t[500010];
bool cmp(qu sa,qu sb)
{
    return sa.r<sb.r;
}
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        s[i]=s[i-1]^a[i];
        mp[s[i]].push_back(i);
    }
    for(int i=0;i<n;i++)
    {
        int j,sb=s[i]^k,l0=0,r0=mp[sb].size()-1,f=0;
        while(l0<=r0)
        {
            int mid=(l0+r0)>>1;
            if(mp[sb][mid]<=i)l0=mid+1;
            else
            {
                j=mid;
                r0=mid-1;
                f=1;
            }
        }
        if(f)t[p++]={i+1,mp[sb][j]};
    }
    sort(t,t+p,cmp);
    int ans=0,lr=0;
    for(int i=0;i<p;i++)
    {
        if(lr<t[i].l)
        {
            ans++;
            lr=t[i].r;
        }
    }
    printf("%lld",ans);
    return 0;
}
