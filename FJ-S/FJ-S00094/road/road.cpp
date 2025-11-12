#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[1005],jl[1005][1005];
int cnt=0,c,a[1005],sum=0;
long long ans=0;
int find(int x)
{
	if(f[x]==x)return x;
	else return find(f[x]);
}
struct node{
	int u,v,w;
}e[2000005];
bool cmp(node x,node y)
{
	if(x.w<y.w)return true;
	else return false;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    f[i]=i;
    for(int i=1;i<=m;i++)
    {
    	cnt++;
	    cin>>e[cnt].u>>e[cnt].v>>e[cnt].w;
	    if(e[cnt].u>e[cnt].v)
	    swap(e[cnt].u,e[cnt].v);
	    if(jl[e[cnt].u][e[cnt].v]==0)
	    jl[e[cnt].u][e[cnt].v]=cnt;
	    else
	    if(e[jl[e[cnt].u][e[cnt].v]].w>e[cnt].w)
	    {
	    	e[jl[e[cnt].u][e[cnt].v]].w=e[cnt].w;
		    cnt--;
		}
	}
    while(k--)
    {
    	cin>>c;
    	for(int i=1;i<=n;i++)
    	cin>>a[i];
    	for(int i=1;i<=n;i++)
    	for(int j=i+1;j<=n;j++)
    	{
    		if(jl[i][j]==0)
    		{
    			cnt++;
    			jl[i][j]=cnt;
    			e[cnt].u=i;
    			e[cnt].v=j;
    			e[cnt].w=a[i]+a[j];
			}
	        else
    		e[jl[i][j]].w=min(e[jl[i][j]].w,a[i]+a[j]);
		}
	}
	sort(e+1,e+cnt,cmp);
	for(int i=1;i;i++)
	{
		if(sum==n-1)break;
		if(find(e[i].u)!=find(e[i].v))
		{
			f[find(e[i].u)]=find(e[i].v);
			ans+=e[i].w;
			sum++;
		}
	}
	cout<<ans;
    return 0;
}
