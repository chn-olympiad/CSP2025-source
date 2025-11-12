#include<bits/stdc++.h>
using namespace std;
long long n,m,k,f[10110],oi,bg,kl,jh,b[20],c[20];
struct node
{
	long long u,v,w,mf;
}a[1101000];
long long find(long long x)
{
	if(f[x]==x)
	{
		return x;
	}
	else return f[x]=find(f[x]);
}
bool cmp(node x,node y)
{
	return x.w+c[x.mf]<y.w+c[y.mf];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
		a[i].mf=0;
	}
	for(int i=1;i<=k;i++)
	{
		long long crh;
		cin>>crh;
		for(int j=1;j<=n;j++)
		{
			int as;
			cin>>as;
			oi++;
			a[m+oi].u=n+i;
			a[m+oi].v=j;
			a[m+oi].w=as;
			a[m+oi].mf=i;
			c[i]=crh;
		}	
	}
	c[0]=0;
	b[0]=1;
	sort(a+1,a+m+oi+1,cmp);
	for(int i=1;i<=m+oi;i++)
	{
		int ss=find(a[i].u);
		int df=find(a[i].v);
		if(ss!=df)
		{
			f[ss]=df;
			bg+=a[i].w;
			if(b[a[i].mf]==0)
			{
				b[a[i].mf]=1;
				bg+=c[a[i].mf];
				c[a[i].mf]=0;
				jh++;
				sort(a+i+2,a+m+oi+1,cmp);
			} 
			kl++;
		}
		if(kl==n+jh-1) break;
	}
	cout<<bg;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
