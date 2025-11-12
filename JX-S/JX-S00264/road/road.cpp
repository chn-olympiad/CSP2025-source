#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const int N=1e4+24,M=2e6+24;
int n,m,k;
int f[N];
int c[20],l[N];
int g[N][20];
struct node
{
    int u,v;
    ll w;
    bool operator<(const node&W)const
    {
        return w<W.w;
    }
}e[M];

inline int find(int x)
{
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
inline ll kr()
{
    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++)f[i]=i;
    ll ans=0;
    for(int i=1;i<=m;i++)
    {
        int fu=find(e[i].u),fv=find(e[i].v);
        ll fw=e[i].w;
        if(fu!=fv)
        {
			//cout<<fw<<"\n";
            ans+=fw;
            f[fu]=fv;
        }
    }
    return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
    if(k!=0)
    {
        bool flg=1;
        for(int i=1;i<=k;i++)
        {
			cin>>c[i];
            if(c[i]!=0)flg=0;
            for(int j=1;j<=n;j++)
            {
                cin>>g[j][i];
                //cout<<g[j][i]<<" ";
                if(g[j][i]==0)
                {
                    l[i]=j;
                }
            }
            if(l[i])
            {
                for(int j=1;j<=n;j++)
                {
                    if(l[i]!=j)
                    {
                        e[++m]={l[i],j,g[j][i]};
                    }
                }
            }
            else flg=0;
        }
        if(flg)
        {
            cout<<kr();
            return 0;
        }
    }
    else
    {
        cout<<kr();
        return 0;
    }
    cout<<kr();
	return 0;
}
