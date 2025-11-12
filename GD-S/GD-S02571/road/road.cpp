#include<bits/stdc++.h>
using namespace std;
long long n,m,bs,bbs,k,c[15],a[15][10005],zw[15],f[10005],zx,w,an,ss,s;
struct node{long long x,y,z;}zb[1000005],b[10005],bb[110005];
long long find(long long x){return f[x]!=x?f[x]=find(f[x]):f[x];}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>zb[i].x>>zb[i].y>>zb[i].z;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		zx=INT_MAX;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]<zx)
			{
				zx=a[i][j];
				zw[i]=j;
			}
		}
//		cout<<zw[i]<<' ';
	}
//	cout<<'\n';
	sort(zb+1,zb+m+1,[](node x,node y){return x.z<y.z;});
	for(int i=1;i<=m;i++)
	{
		if(find(zb[i].x)!=find(zb[i].y))
		{
			b[++bs]={zb[i].x,zb[i].y,zb[i].z};
			f[find(zb[i].x)]=find(zb[i].y);
			ss+=zb[i].z;
		}
	}
//	cout<<ss<<'\n';
	an=LONG_LONG_MAX;
	for(int i=0;i<(1<<k);i++)
	{
		s=0;
		for(int j=1;j<=bs;j++)bb[j]=b[j];
		for(int j=1;j<=n;j++)f[j]=j;
		bbs=bs;
		for(int j=1;j<=k;j++)
		{
			if((i>>j-1)&1)
			{
				s+=a[j][zw[j]]+c[j];
				for(int o=1;o<=n;o++)
				{
					if(o!=zw[j])
					{
						bb[++bbs]={zw[j],o,a[j][o]};
					}
				}
			}
		}
		sort(bb+1,bb+bbs+1,[](node x,node y){return x.z<y.z;});
		for(int j=1;j<=bbs;j++)
		{
			if(find(bb[j].x)!=find(bb[j].y))
			{
				f[find(bb[j].x)]=find(bb[j].y);
				s+=bb[j].z;
			}
//			cout<<bb[j].x<<' '<<bb[j].y<<' '<<bb[j].z<<' '<<find(bb[j].x)<<' '<<find(bb[j].y)<<'\n';
		}
		an=min(an,s);
//		cout<<i<<' '<<s<<'\n';
	}
	cout<<an;
	return 0;
}
