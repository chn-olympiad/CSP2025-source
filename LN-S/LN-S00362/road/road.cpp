#include <bits/stdc++.h>
using namespace std;
int main( )
{
	int n,m,k,ui[10000],vi[10000],wi[10000],s1=0,s2=0,a[10000][10000],h=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>ui[i]>>vi[i]>>wi[i];
		if(wi[i]>wi[i+1])
		{
			swap(wi[i],wi[i+1]);
		}
	}
	s1=s1+wi[1]+wi[2];	
	for(int f=1;f<=5;f++)
	{
		for(int j=1;j<=k;j++)
		{
			cin>>a[f][j];
			if(a[f][1]>a[f+1][1])
			{
				h=f-1;
			}
			if(j>=2)
			{
				if(a[f][j]<a[f][j-1])
				{
					swap(a[f][j],a[f][j-1]);
				}
			}
		}
	}		
	s2=s2+a[h][1]+a[h][2];	
	cout<<s1+s2;		
	//freopen(road.in,"r",stdin)
	//freopen(road.out,"w",stdout)
	return 0;
}
