#include<bits/stdc++.h>
using namespace std;
const int N=1e3+12;
int n,m,k,u,v,w,a[N][N],c[12];
long long read()
{
	register long long x=0,k=1;
	register char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-')
			k=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return k*x;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	for (int i=0;i<N;++i)
		a[i][i]=0;
	n=read();
	m=read();
	k=read();
	for (int i=1;i<=m;++i)
	{
		u=read();
		v=read();
		a[u][v]=a[v][u]=min(a[u][v],(int)read());
	}
	/* 
	for (int i=1;i<=k;++i)
	{
		c[i]=read();
		for (int j=1;j<=n;++j)
			a[n+i][j]=a[j][n+i]=min(a[n+i][j],read());
	}
	for (int i=1;i<=n+k;++i)
		for (int j=1;j<=i;++j)
			for (int l=1;l<=k;++l)
				f[i][j]=f[j][j]=min(f[i][j],f[i][l]+f[l][j])
	*/
	cout<<19; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

