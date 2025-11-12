#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u,v,w;
};
const int N=1e4+5,M=1e6+5,K=15;
int n,m,m2,k,c[K],f[N+K];
node road[M],road2[N*K];
bool ss[K];
long long ans=LONG_LONG_MAX;
inline bool cmp(node x,node y)
{
    return x.w<y.w;
}
inline int find(int x)
{
    while(f[x]!=x)
    {
        x=f[x];
    }
    return x;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>road[i].u>>road[i].v>>road[i].w;
    }
    sort(road+1,road+m+1,cmp);
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            int ww;
            cin>>ww;
            road2[++m2].u=i+n;
            road2[m2].v=j;
            road2[m2].w=ww;
        }
    }
    sort(road2+1,road2+m2+1,cmp);
    for(int o=0;o<=(1<<k)-1;o++)
    {
        int p=o,cnt=n-1,l=1,r=1;
        long long back=0;
        for(int i=1;i<=k;i++)
        {
            if(p&1)
            {
                ss[i]=1;
                cnt++;
                back+=c[i];
            }
            else
            {
                ss[i]=0;
            }
            p>>=1;
        }
        for(int i=1;i<=n+k;i++)
        {
            f[i]=i;
        }
        while(cnt)
        {
            if(r>m2||road[l].w<=road2[r].w)
            {
                int ll=road[l].u,rr=road[l].v,fl=find(ll),fr=find(rr);
                if(fl!=fr)
                {
                    f[fl]=fr;
                    f[ll]=fr;
                    f[rr]=fr;
                    back+=road[l].w;
                    cnt--;
                }
                l++;
            }
            else if(ss[road2[r].u-n])
            {
                int ll=road2[r].u,rr=road2[r].v,fl=find(ll),fr=find(rr);
                if(fl!=fr)
                {
                    f[fl]=fr;
                    f[ll]=fr;
                    f[rr]=fr;
                    back+=road2[r].w;
                    cnt--;
                }
                r++;
            }
            else
            {
                r++;
            }
        }
        ans=min(ans,back);
    }
    cout<<ans;
    return 0;
}