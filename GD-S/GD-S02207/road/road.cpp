#include<cstdio>
#include<algorithm>
using namespace std;
long long i,j,t,z,n,m,k,u[1100000],v[1100000],w[1100000],num[1100000],f[11000],c[20],a[20][11000],uu[1100][11000],vv[1100][11000],ww[1100][11000],ans;
void read(long long &x)
{
	int c=getchar();
	while(c<'0'||c>'9')
	c=getchar();
	x=c-'0';
	while(1)
	{
		c=getchar();
		if(c<'0'||c>'9')
		return;
		x=x*10+c-'0';
	}
}
long long root(long long a)
{
	if(f[a]==0)
	return a;
	else
	return f[a]=root(f[a]);
}
bool in(long long a,long long b)
{
	a=root(a);
	b=root(b);
	if(a==b)
	return false;
	f[a]=b;
	return true;
}
long long mst(long long wh,long long r)
{
	long long i,cnt=0,ans=0;
	for(i=1;i<=n+k;i++)
	f[i]=0;
	for(i=1;i<=r;i++)
	num[i]=i;
	sort(num+1,num+r+1,[](long long a,long long b)->bool{return w[a]<w[b]||w[a]==w[b]&&a<b;});
	for(i=1;i<=r;i++)
	if(in(u[num[i]],v[num[i]]))
	{
		ans=ans+w[num[i]];
		cnt++;
		uu[wh][cnt]=u[num[i]];
		vv[wh][cnt]=v[num[i]];
		ww[wh][cnt]=w[num[i]];
	}
	uu[wh][0]=cnt;
	return ans;
}
main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	for(i=1;i<=m;i++)
	{
		read(u[i]);
		read(v[i]);
		read(w[i]);
	}
	for(i=1;i<=k;i++)
	{
		read(c[i]);
		for(j=1;j<=n;j++)
		read(a[i][j]);
	}
	ans=mst(0,m);
	for(i=1;i<1<<k;i++)
	{
		t=i&i-1;
		z=1;
		while(1<<z-1!=(i^t))
		z++;
		for(j=1;j<=uu[t][0];j++)
		{
			u[j]=uu[t][j];
			v[j]=vv[t][j];
			w[j]=ww[t][j];
		}
		for(j=1;j<=n;j++)
		{
			u[j+uu[t][0]]=z+n;
			v[j+uu[t][0]]=j;
			w[j+uu[t][0]]=a[z][j];
		}
		z=mst(i,n+uu[t][0]);
		for(j=1;j<=k;j++)
		if(i&1<<j-1)
		z=z+c[j];
		if(z<ans)
		ans=z;
	}
	printf("%lld",ans);
}
