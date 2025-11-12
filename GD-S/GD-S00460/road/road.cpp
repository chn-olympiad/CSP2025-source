#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	


	int n,m,k;
	cin>>n>>m>>k;
	int a,b,c,e;
	int x=0,y=10,z=0,p=0,q=0;
	int h[1000];
	int s[10000];
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		if(y>c)
		{
			z=y;
			y=c;
			h[a]=a;
			h[b]=b;
		}
	}
	for(int j=1;j<=k;j++)
	{
		x=10000;
		for(int d=1;d<=n+1;d++)
		{
			cin>>s[d];
		}
		if(x>s[1])
		{
			x=s[1];
			for(int l=1;l<=m;l++)
			{
				if(h[l]=0)
				{
					p=s[l];
				}
				if(s[l]>s[l])
				{
					q=s[l+2];
				}
			}
		}
		
	}
	cout<<x+y+z+p+q;
	return 0;
 } 
