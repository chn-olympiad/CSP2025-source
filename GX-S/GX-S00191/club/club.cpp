#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long t,n;
long long cnt[5];
long long maxn,secn,ans;
struct Node
{
    long long v[5];
    long long val,pos,pos1,mx;
}a[N];
bool cmp(Node a,Node b)
{
    return a.val<b.val;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(cnt,0,sizeof cnt);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)
                cin>>a[i].v[j];
        for(int i=1;i<=n;i++)
        {
            maxn=0;
            secn=0;
            for(int j=1;j<=3;j++)
            {
                if(a[i].v[j]>maxn)
                    secn=maxn,a[i].pos1=a[i].pos,maxn=a[i].v[j],a[i].pos=j;
                else if(a[i].v[j]>secn)
                    secn=a[i].v[j],a[i].pos1=j;
            }
            a[i].val=secn-maxn;
            a[i].mx=maxn;
        }
        sort(a+1,a+n+1,cmp);
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt[a[i].pos]<n/2)
            {
                cnt[a[i].pos]++;
                ans+=a[i].mx;
            }
            else
            {
                ans+=a[i].mx+a[i].val;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
