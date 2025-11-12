#include <bits/stdc++.h>
using namespace std;
struct road
{
    int u,v,price;
};
vector<road> r;
bool cmp(road a,road b)
{
    return a.price>b.price;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        r.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++)
    {
        int a,c;
        cin>>c;
        for(int j=1;j<=n;j++)
        {
            cin>>a;
        }
    }
    if(k==0)
    {
        int cnt[10002]={0};
        int sum=0;
        for(int i=0;i<r.size();i++)
        {
            cnt[r[i].u]++;
            cnt[r[i].v]++;
            sum+=r[i].price;
        }
        sort(r.begin(),r.end(),cmp);
        for(int i=0;i<r.size();i++)
        {
            if(cnt[r[i].u]>1&&cnt[r[i].v]>1)
            {
                sum-=r[i].price;
                cnt[r[i].u]--;
                cnt[r[i].v]--;
            }
        }
        cout<<sum;
        return 0;
    }
    cout<<0;
    return 0;
}

