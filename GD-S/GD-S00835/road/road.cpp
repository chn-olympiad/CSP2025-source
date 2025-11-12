#include<bits/stdc++.h>
using namespace std;
long long n,m,u,q,v,w,a[520][520],l[520][520][55],t[520][520],opl,lazy[1000005],op[1000005],cd,lop,mi=1e15,o[1000005];
void rop(long long x,long long y,long long opl)
{
	memset(op,0,sizeof(op));
	cd=0;
	for(int i=1;i<=t[x][y];i++)
	{
		if(op[l[x][y][i]]==0)
		{
			op[l[x][y][i]]=1;
			cd++;
			l[x][opl][cd]=l[x][y][i];
		}
	}
	for(int i=1;i<=t[y][opl];i++)
	{
		if(op[l[y][opl][i]]==0)
		{
			op[l[y][opl][i]]=1;
			cd++;
			l[x][opl][cd]=l[y][opl][i];
		}
	}
	t[x][opl]=cd;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>u;
	for(int i=1;i<=m;i++)
	{
		cin>>q>>v>>w;
		a[q][v]=w;
		a[v][q]=w;
		t[q][v]++;
		l[q][v][t[q][v]]=q;
		t[q][v]++;
		l[q][v][t[q][v]]=v;
		t[v][q]++;
		l[v][q][t[v][q]]=q;
		t[v][q]++;
		l[v][q][t[v][q]]=v;
	}
	for(int i=1;i<=u;i++)
	{
		cin>>opl;
		lazy[n+i]=opl;
		for(int j=1;j<=n;j++)
		{
			cin>>w;
			a[n+i][j]=w;
			a[j][n+i]=w;
			t[n+i][j]++;
			l[n+i][j][t[n+i][j]]=n+i;
			t[n+i][j]++;
			l[n+i][j][t[n+i][j]]=j;
			t[j][n+i]++;
			l[j][n+i][t[j][n+i]]=j;
			t[j][n+i]++;
			l[j][n+i][t[j][n+i]]=n+i;
		}
	}
	for(int i=1;i<=n+u;i++)
	{
		for(int j=1;j<=n+u;j++)
		{
			if(a[i][j]==0)
			{
				a[i][j]=0x3f3f3f3f3f3f3f3f;
			}
			if(i==j)
			{
				a[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n+u;i++)
	{
		for(int j=1;j<=n+u;j++)
		{
			for(int l=1;l<=n+u;l++)
			{
				if(a[j][i]+a[i][l]<a[j][l]&&a[j][i]!=0x3f3f3f3f3f3f3f3f&&a[i][l]!=0x3f3f3f3f3f3f3f3f)
				{
					a[j][l]=a[j][i]+a[i][l];
					rop(j,i,l);
				}
			}
		}
	}
	for(int i=1;i<=n+u;i++)
	{
		for(int j=1;j<=n+u;j++)
		{
			lop=0;
			memset(op,0,sizeof(op));
			cd=0;
			for(int io=1;io<=t[i][j];io++)
			{
				if(l[i][j][io]<=n)
				{
					cd++;
				}
				else
				{
					lop+=lazy[l[i][j][io]];
					if(lazy[l[i][j][io]]!=0)
					{
						o[l[i][j][io]]=lazy[l[i][j][io]];
						lazy[l[i][j][io]]=0;
					}
				}
			}
			for(int io=1;io<=t[i][j];io++)
			{
				lazy[l[i][j][io]]=o[l[i][j][io]];
				o[l[i][j][io]]=0;
			}
			mi=min(mi,a[i][j]+lop);
		}
	}
	cout<<mi;
	
	return 0;
}
/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/
