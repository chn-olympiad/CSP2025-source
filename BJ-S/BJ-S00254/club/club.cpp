#include<bits/stdc++.h>
using namespace std;
struct node
{
    pair<long long,long long> a[5];
    long long s[5];
    long long c[5];
}d[100010];
bool cmp1(pair<long long,long long> x,pair<long long,long long> y)
{
    return x.first>y.first;
}
bool cmp2(node x,node y)
{
    if(x.c[1]!=y.c[1]) return x.c[1]>y.c[1];
    else return x.c[2]>y.c[2];
}
long long n,cnt[4],ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i].s[1]>>d[i].s[2]>>d[i].s[3];
            d[i].a[1]={d[i].s[1],1};
            d[i].a[2]={d[i].s[2],2};
            d[i].a[3]={d[i].s[3],3};
            sort(d[i].a+1,d[i].a+4,cmp1);
            d[i].c[1]=d[i].a[1].first-d[i].a[2].first;
            d[i].c[2]=d[i].a[2].first-d[i].a[3].first;
        }
        sort(d+1,d+n+1,cmp2);
        for(int i=1;i<=n;i++)
        {
            if(cnt[d[i].a[1].second]+1<=n/2)
            {
                ans+=d[i].a[1].first;
                cnt[d[i].a[1].second]++;
            }
            else if(cnt[d[i].a[2].second]+1<=n/2)
            {
                ans+=d[i].a[2].first;
                cnt[d[i].a[2].second]++;
            }
            else if(cnt[d[i].a[3].second]+1<=n/2)
            {
                ans+=d[i].a[3].first;
                cnt[d[i].a[3].second]++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
