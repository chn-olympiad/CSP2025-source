#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],y[500005];
pair<int,int> p[1000005];
bool cmp(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.second==p2.second) return p1.first<p2.first;
    return p1.second<p2.second;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        y[i]=y[i-1]^a[i];
    }
    int sum=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if((y[j]^y[i-1])==k)
            {
                p[++sum].first=i;
                p[sum].second=j;
            }
        }
    }
    sort(p+1,p+sum+1,cmp);
    int last=0;
    for(int i=1;i<=sum;i++)
    {
        if(p[i].first>last)
        {
            ans++;
            last=p[i].second;
        }
    }
    cout<<ans<<'\n';
    return 0;
}