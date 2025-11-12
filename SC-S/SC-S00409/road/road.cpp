#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[1001],cnt,ans,c;
int find(int x)
{
	if(x==f[x]) return x;
	f[x]=find(f[x]);
	return f[x];
}
void hebin(int x,int y)
{
	int fx=f[x],fy=f[y];
	f[fx]=fy;
}
struct node
{
	int x,y,z;
}a[1000001];
struct node1
{
	int c,q[1001];
}b[11];
bool cmp(node q,node w)
{
	return q.z<w.z;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	cnt=m;
	for(int i=1;i<=k;i++)
	{
		cin>>b[i].c;
		for(int j=1;j<=n;j++)
		{
			cin>>b[i].q[j];
		}
	} 
	if(k)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					c=INT_MAX;
					for(int w=1;w<=k;w++)
					{
						c=min(c,b[w].q[i]+b[w].q[j]);
					}
				}
				cnt++;
				a[cnt].x=i;
				a[cnt].y=j;
				a[cnt].z=c;
			}
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	int u=0;
	for(int i=1;i<=cnt;i++)
	{
		int l=a[i].x,r=a[i].y;
		if(find(l)!=find(r))
		{
			hebin(l,r);
			ans+=a[i].z;
			u++;
		}
		if(n==n-1) break;
	}
	cout<<ans;
	return 0;
}