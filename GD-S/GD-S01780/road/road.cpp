#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,fa[10005],d[15],a[15][10005],flags[1005][1005],ans;
struct node{
	int x,y,z;
}b[1000005],c[2500005];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;
		b[i]={x,y,z};
	}
	if(!k)
	{
		sort(b+1,b+m+1,[&](node l1,node l2){return l1.z<l2.z;});
		int s=0;
		for(int i=1;i<=m;i++){
			int x=find(b[i].x),y=find(b[i].y);
			if(x!=y) fa[x]=y,s++,ans+=b[i].z;
			if(s==n-1) break;
		}
		return cout<<ans,0; 
	}
	int flag=0;
	for(int i=1;i<=k;i++){
		cin>>d[i];
		if(d[i]) flag=1;
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(!flag&&n<=1000)
	{
		memset(flags,0x3f3f3f3f,sizeof(flags));
		int cnt=0;
		for(int i=1;i<=m;i++){
			flags[b[i].x][b[i].y]=flags[b[i].y][b[i].x]=b[i].z;
			c[++cnt]=b[i];
		}
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				for(int p=1;p<=n;p++)
					flags[j][p]=flags[p][j]=min(min(flags[j][p],flags[p][j]),a[i][j]+a[i][p]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				c[++cnt]={i,j,flags[i][j]};
		sort(c+1,c+cnt+1,[&](node l1,node l2){return l1.z<l2.z;});
		int s=0;
		for(int i=1;i<=cnt;i++){
			int x=find(c[i].x),y=find(c[i].y);
			if(x!=y) fa[x]=y,s++,ans+=c[i].z;
			if(s==n-1) break;
		}
		return cout<<ans,0;
	}
	
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
*/
