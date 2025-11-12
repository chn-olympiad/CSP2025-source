#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,ans;
map<int,int>b;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) b[i*20000+j]=1000000005;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		b[u*20000+v]=b[v*20000+u]=min(w,min(b[v*20000+u],b[u*20000+v]));
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) if(b[i*20000+j]!=1000000005) ans+=b[i*20000+j],b[i*20000+j]=b[j*20000+i]=1000000005;
	cout<<ans;
	return 0;
}
