#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int N=1e5+100;

int n;
struct NODE{
    int a[4];
    int b;
}dt[N];
vector<int> G[4];
int k,max_size;
ll ans;

bool cmp(int a,int b)
{
    return (dt[a].a[k]-dt[a].b)<(dt[b].a[k]-dt[b].b);
}

void work()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&dt[i].a[1],&dt[i].a[2],&dt[i].a[3]);
        if(dt[i].a[1]>=dt[i].a[2] && dt[i].a[1]>=dt[i].a[3])
            G[1].pb(i),ans+=dt[i].a[1],dt[i].b=max(dt[i].a[2],dt[i].a[3]);
        else if(dt[i].a[2]>=dt[i].a[1] && dt[i].a[2]>=dt[i].a[3])
            G[2].pb(i),ans+=dt[i].a[2],dt[i].b=max(dt[i].a[1],dt[i].a[3]);
        else
            G[3].pb(i),ans+=dt[i].a[3],dt[i].b=max(dt[i].a[2],dt[i].a[1]);
      //  cout<<ans<<endl;
    }
    for(int i=1;i<=3;i++)
        if(G[i].size()>=max_size)
            k=i,max_size=G[i].size();
    if(G[k].size()>n/2)
    {
        sort(G[k].begin(),G[k].end(),cmp);
        for(int i=1;i<=G[k].size()-n/2;i++)
            ans-=dt[G[k][i-1]].a[k],ans+=dt[G[k][i-1]].b;
    }
    cout<<ans<<endl;

    ans=0,max_size=0;
    for(int i=1;i<=3;i++)   G[i].clear();
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)  work();
    return 0;
}
