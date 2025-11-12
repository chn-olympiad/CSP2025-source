#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1005][1005],b[15],c[10005],s;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=min(a[x][y],z);
		a[y][x]=a[x][y];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>b[i];
		for(int j=1;j<=n;j++)
		{
			cin>>c[j];
			for(int ij=1;ij<j;ij++)
				a[c[ij]][j]=0,a[j][c[ij]]=0;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int ij=1;ij<=n;ij++)
				if(a[ij][i]+a[i][j]<a[ij][j])a[ij][j]=a[ij][i]+a[i][j];
	for(int i=1;i<=n;i++)
	{
		int f=1000000000;
		for(int j=1;j<=n;j++)
			if(a[i][j]<f)f=a[i][j];
		s+=f;
	}
	cout<<s;
	return 0;
}
