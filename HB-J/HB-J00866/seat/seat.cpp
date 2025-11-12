#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","n","m",stdin);
	freopen("seat.out","mu","nu",stdout);
	int n,m,x,y,z,nu,mu;
	cin>>n>>m;
	int a[10000005]={};
	for(int i=0;i<(n*m);i++)
	{
		cin>>a[i];
	}
	z=a[0];
	for(int j=0;j<=n*m;j++)
	{
		for(int k=j;k<=n*m;k++)
		{
			if(a[j]<a[k])
			{
				x=a[j];
				y=a[k];
				a[j]=y;
				a[k]=x;
			}
		}
	}
	for(int l=0;l<n*m;l++)
	{
		if(a[l]==z)
		{
			if((((l-1)/m)/2)==1)
			{
				mu=m-(l-((l-1)/m)*m)+1;
				nu=((l-1)/m)+1;
			}
			if((((l-1)/m)/2)==0)
			{
				mu=l-((l-1)/m)*m;
				nu=((l-1)/m)+1;
			}
			break;
		}
	}
	cout<<mu<<nu<<endl;
	return 0;
}
