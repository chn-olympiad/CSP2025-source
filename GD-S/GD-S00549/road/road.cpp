#include <bits/stdc++.h>

using namespace std;

bool bo[200001];
int n,m,k;
int oa[200001],ob[200001],ovalue[200001];
int a[200001],b[200001],value[200001];
int z;
int minx;

void bobsort()
{
	for(int i=0;i<m+n-1;i++)
	{
		for(int j=0;j<m+n-1;j++)
		{
			if(value[j]>value[j+1])
			{
				int r=a[j];
				a[j]=a[j+1];
				a[j+1]=r;
				
				r=b[j];
				b[j]=b[j+1];
				b[j+1]=r;
				
				r=value[j];
				value[j]=value[j+1];
				value[j+1]=r;
			}
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>oa[i]>>ob[i]>>ovalue[i];
	}
	z=0;
	for(int j=0;j<m+n;j++)
	{
		if(bo[a[j]]==0||bo[b[j]]==0)
		{
			z+=value[j];
			bo[a[j]]=1;
			bo[b[j]]=1;
		}
	}
	minx=z;
 	
	for(int i=n;i<n+k;i++)
	{
		int t=0;
		cin>>t;
		for(int u=m;u<m+n;u++)
		{
			cin>>ovalue[u];
			oa[u]=i;
			ob[u]=u-m;
		}
		for(int j=0;j<m+n;j++)
		{
			a[j]=oa[j];
			b[j]=ob[j];
		}
		bobsort();
		memset(bo,0,sizeof(bo));
		z=t;
		for(int j=0;j<m+n;j++)
		{
			if(bo[a[j]]==0||bo[b[j]]==0)
			{
				z+=value[j];
				bo[a[j]]=1;
				bo[b[j]]=1;
			}
		}
		minx=min(minx,z);
	}
	cout<<minx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
