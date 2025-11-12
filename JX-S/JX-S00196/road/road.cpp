#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
int n,m,k,a[1000001],g=0,l=INT_MAX,h=INT_MAX;
cin>>n>>m>>k;
for(int i=1;i<=m;i++)
{
	int o,p;
	cin>>o>>p>>a[i];
}

for(int i=1;i<=k;i++)
{int r;
	cin>>r;
	l=min(l,r);
	for(int j=1;j<=m;j++)
	{
		int u;
		cin>>u;
		h=min(h,u);
		a[j]=min(a[j],h+l);
	}
}
sort(a+1,a+m+1);
for(int i=1;i<=n;i++)
{
	g+=a[i];
}
cout<<g;
return 0;
}
