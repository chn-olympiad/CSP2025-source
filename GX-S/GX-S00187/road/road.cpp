#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
long long n,m,k,a,b,c,h[MAXN],to[MAXN],cnt,tal[MAXN],vis[MAXN],u,dis;
long long sum;
int main()
{
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(int i=1;i<=n;i++)
{
cin>>a>>b>>c;
to[i]=b;
tal[i]=c;
h[i]=h[a]-1;
h[a]=i+1;
}
vis[1]=1;
for(int i=2;i<=n;i++)
{
	dis=1e9+5;
	for(int j=h[i];j>0;j=h[j])
	{
		if(dis>tal[j]&&(vis[to[j]]==0||vis[i]==0))
		{
			u=to[j];
			dis=tal[j];
		}
	}
	vis[u]=1;
	sum+=dis;
}
cout<<sum;

return 0;
}
