#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,cnt;
ll ans;
struct node
{
    int nx,to,w;
}edge[4000005];
int head[1000005],c[15],a[15][1000005];
void add(int u,int v,int w)
{
    cnt++;
    edge[cnt].w=w;
    edge[cnt].to=v;
    edge[cnt].nx=head[u];
    head[u]=cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        add(u,v,w);
        add(v,u,w);
        ans+=w;
    }
    for(int i=1;i<=k;i++)
    {
        cin >> c[i];
        for(int j=1;j<=n;j++) cin >> a[i][j];
    }
    cout << ans;
	return 0;
}
