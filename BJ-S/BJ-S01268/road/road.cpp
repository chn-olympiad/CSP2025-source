#include<bits/stdc++.h>
using namespace std;
long long ans=1e18;
int f[10020],c[20];
struct node
{
	int x,y,z,b;
}a[1100010];
bool cmp(node x,node y)
{
	return x.z<y.z;
}
int find(int x)
{
	if(f[x]==x)
		return x;
	f[x]=find(f[x]);
	return f[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k,i,j;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		a[i].b=0;
	}
	for(i=1;i<=k;i++)
	{
		cin>>c[i];
		for(j=1;j<=n;j++)
		{
			++m;
			cin>>a[m].z;
			a[m].x=j;
			a[m].y=n+i;
			a[m].b=i;
		}
	}
	sort(a+1,a+m+1,cmp);
	int l=(1<<k);
	for(i=0;i<l;i++)
	{
		for(j=1;j<=n+k;j++)
			f[j]=j;
		long long s=0,cnt=0,s2=1;
		for(j=0;j<k;j++)
		{
			if(i&(1<<j))
			{
				s+=c[j+1];
				cnt++;
			}
		}
		j=1;
		while(s2<(n+cnt))
		{
			int x=a[j].x,y=a[j].y,z=a[j].z,b=a[j].b;
			if(b==0||(b>0)&&(i&(1<<(b-1))))
			{
				int t1=find(x);
				int t2=find(y);
				if(t1!=t2)
				{
					f[t1]=t2;
					s+=z;
					s2++;
				}
			}
			j++;
		}
		ans=min(ans,s);
	}	
	cout<<ans;
	return 0;
}
