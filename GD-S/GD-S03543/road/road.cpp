#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int x,y,z;
}a[1000005],b[50005];
int f[10005],c[15];
int w[15][10005];
bool cmp(node A,node B)
{
	return A.z<B.z;
}
int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>w[i][j];
	}
	sort(a+1,a+m+1,cmp);
		int ans=1e18;
		int p=0;
		if((1<<k)*m>50000000) p=(1<<k)-1;
		for(int i=p;i<(1<<k);i++)
		{
			for(int j=1;j<=n+k;j++) f[j]=j;
			int cnt=0,sum=0;
			for(int j=1;j<=k;j++)
			{
				if(1<<(j-1)&i)
				{
					sum+=c[j];
					for(int l=1;l<=n;l++)
					{
						cnt++;
						b[cnt].x=j+n;
						b[cnt].y=l;
						b[cnt].z=w[j][l];
					}
				}
			}
			sort(b+1,b+cnt+1,cmp);
			int l=1,r=1;
			while(l<=m||r<=cnt)
			{
				int x,y,num=0;
				if((a[l].z<b[r].z&&l<=m)||r>cnt)
				{
					x=find(a[l].x),y=find(a[l].y);
					num=a[l].z;
					l++;
				}
				else
				{
					x=find(b[r].x),y=find(b[r].y);
					num=b[r].z;
					r++;
				}
				if(x==y) continue;
				f[x]=y;
				sum+=num;
			}
			ans=min(ans,sum);
		}
		cout<<ans;
	return 0;
}
