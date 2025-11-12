#include<bits/stdc++.h>
using namespace std;
#define int long long
struct xy
{
	int x,y,z;
}edge[1010000],extra[101000];
inline bool operator <(xy x,xy y)
{
	return x.z<y.z;
}
int elen,c[20],a[20][10100],f[2010000],n,m,k,ans=LONG_LONG_MAX,cnt;
inline int find(int k)
{
	if(f[k]!=k)f[k]=find(f[k]);
	return f[k];
}
inline int scs()
{
	int num=0,u1=1,u2=1,res=0;
	while(num<n+cnt-1)
	{
		if(edge[u1].z<=extra[u2].z)
		{
			//printf("%lld %lld %lld\n",edge[u1].x,edge[u1].y,edge[u1].z);
			if(find(edge[u1].x)!=find(edge[u1].y))
			{
				num++;
				f[find(edge[u1].x)]=find(edge[u1].y);
				res+=edge[u1].z;
			}
			u1++;
		}
		else
		{
			//printf("%lld %lld %lld\n",extra[u2].x,extra[u2].y,extra[u2].z);
			if(find(extra[u2].x)!=find(extra[u2].y))
			{
				num++;
				f[find(extra[u2].x)]=find(extra[u2].y);
				res+=extra[u2].z;
			}
			u2++;
		}
		//printf("%lld\n",num);
		//getchar();
	}
	return res;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//double tme1=clock(),tme2;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;++i)
	{
		scanf("%lld%lld%lld",&edge[i].x,&edge[i].y,&edge[i].z);
	}
	sort(edge+1,edge+1+m);
	edge[m+1]=(xy){0,0,INT_MAX};
	bool flag=1;
	for(int i=1;i<=k;++i)
	{
		scanf("%lld",&c[i]);
		if(c[i]!=0)flag=0;
		for(int j=1;j<=n;++j)scanf("%lld",&a[i][j]);
	}
	if(flag==0)
	{
		for(int i=0;i<(1<<k);++i)
		{
			for(int j=1;j<=n+20;++j)f[j]=j;
			elen=0;
			cnt=0;
			int cst=0;
			for(int j=1;j<=k;++j)
			{
				if((1<<(j-1))&i)
				{
					cnt++;cst+=c[j];
					for(int l=1;l<=n;++l)extra[++elen]=(xy){n+cnt,l,a[j][l]};
				}
			}
			sort(extra+1,extra+elen+1);
			extra[elen+1]=(xy){0,0,INT_MAX};
			ans=min(ans,scs()+cst);
			//printf("%lld %lld\n",ans,i);
		}
	}
	else
	{
		int i=(1<<k)-1;
		for(int j=1;j<=n+20;++j)f[j]=j;
		elen=0;
		cnt=0;
		int cst=0;
		for(int j=1;j<=k;++j)
		{
			if((1<<(j-1))&i)
			{
				cnt++;cst+=c[j];
				for(int l=1;l<=n;++l)extra[++elen]=(xy){n+cnt,l,a[j][l]};
			}
		}
		sort(extra+1,extra+elen+1);
		extra[elen+1]=(xy){0,0,INT_MAX};
		ans=min(ans,scs()+cst);
	}
	printf("%lld\n",ans);
	//tme2=clock();
	//cerr<<(tme2-tme1)/CLOCKS_PER_SEC<<endl;
	return 0;
}
