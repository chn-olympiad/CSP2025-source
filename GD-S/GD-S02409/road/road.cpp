#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int x,y,z;
}a[2000005];
int b[15][10005],c[15],f[20005],mi=1e18;
int fd(int x)
{
	if(f[x]==x)return f[x];
	f[x]=fd(f[x]);
	return f[x];
}
bool cmp(node l,node r)
{
	return l.z<r.z; 
 } 
int n,m,k;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].z;
    for(int i=1;i<=k;i++)
    {
    	cin>>c[i];
    	for(int j=1;j<=n;j++)cin>>b[i][j];
	}
	int u=(1<<k)-1;
	for(int S=0;S<=u;S++)
	{
		int ans=0;
		int ss=0;
		for(int i=1;i<=n;i++)f[i]=i;
		int mm=m;
		for(int i=1;i<=k;i++)
		{
			if((1<<(i-1))&S)
			{
				ss++;
				f[n+ss]=n+ss;
				ans+=c[i];
				for(int j=1;j<=n;j++)
				{
					a[++mm]={n+ss,j,b[i][j]};
				}
			}
		} 
		int tt=0;
		sort(a+1,a+1+mm,cmp);
		for(int i=1;i<=mm;i++)
		{
			int x=a[i].x,y=a[i].y,z=a[i].z;
			int xx=fd(x),yy=fd(y);
			if(xx!=yy)
			{
				f[x]=yy; 
				ans+=z;
				tt++;
			} 
			if(tt==n+ss-1)break;
		}
		
		mi=min(mi,ans);
	} 
	cout<<mi;
   return 0;
}

